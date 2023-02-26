#include <env.h>
#include <lib.h>
#include <mmu.h>
#define debug 0

static int pipe_close(struct Fd *);
static int pipe_read(struct Fd *fd, void *buf, u_int n, u_int offset);
static int pipe_stat(struct Fd *, struct Stat *);
static int pipe_write(struct Fd *fd, const void *buf, u_int n, u_int offset);

struct Dev devpipe = {
    .dev_id = 'p',
    .dev_name = "pipe",
    .dev_read = pipe_read,
    .dev_write = pipe_write,
    .dev_close = pipe_close,
    .dev_stat = pipe_stat,
};

#define BY2PIPE 32 // small to provoke races

struct Pipe {
	u_int p_rpos;	       // read position
	u_int p_wpos;	       // write position
	u_char p_buf[BY2PIPE]; // data buffer
};

int pipe(int pfd[2]) {
	int r, va;
	struct Fd *fd0, *fd1;

	// allocate the file descriptor table entries
	if ((r = fd_alloc(&fd0)) < 0 || (r = syscall_mem_alloc(0, fd0, PTE_D | PTE_LIBRARY)) < 0) {
		goto err;
	}

	if ((r = fd_alloc(&fd1)) < 0 || (r = syscall_mem_alloc(0, fd1, PTE_D | PTE_LIBRARY)) < 0) {
		goto err1;
	}

	// allocate the pipe structure as first data page in both
	va = fd2data(fd0);
	if ((r = syscall_mem_alloc(0, (void *)va, PTE_D | PTE_LIBRARY)) < 0) {
		goto err2;
	}
	if ((r = syscall_mem_map(0, (void *)va, 0, (void *)fd2data(fd1), PTE_D | PTE_LIBRARY)) <
	    0) {
		goto err3;
	}

	// set up fd structures
	fd0->fd_dev_id = devpipe.dev_id;
	fd0->fd_omode = O_RDONLY;

	fd1->fd_dev_id = devpipe.dev_id;
	fd1->fd_omode = O_WRONLY;

	debugf("[%08x] pipecreate \n", env->env_id, vpt[VPN(va)]);

	pfd[0] = fd2num(fd0);
	pfd[1] = fd2num(fd1);
	return 0;

err3:
	syscall_mem_unmap(0, (void *)va);
err2:
	syscall_mem_unmap(0, fd1);
err1:
	syscall_mem_unmap(0, fd0);
err:
	return r;
}

static int _pipe_is_closed(struct Fd *fd, struct Pipe *p) {
	// Check pageref(fd) and pageref(p),
	// returning 1 if they're the same, 0 otherwise.
	//
	// The logic here is that pageref(p) is the total
	// number of readers *and* writers, whereas pageref(fd)
	// is the number of file descriptors like fd (readers if fd is
	// a reader, writers if fd is a writer).
	//
	// If the number of file descriptors like fd is equal
	// to the total number of readers and writers, then
	// everybody left is what fd is.  So the other end of
	// the pipe is closed.
	int fd_ref, pipe_ref, runs;
	/* Exercise 6.1: Your code here. (1/3) */

	return fd_ref == pipe_ref;
}

static int pipe_read(struct Fd *fd, void *vbuf, u_int n, u_int offset) {
	// Your code here.  See the lab text for a description of
	// what pipe_read needs to do.  Write a loop that
	// transfers one byte at a time.  If you decide you need
	// to yield (because the pipe is empty), only yield if
	// you have not yet copied any bytes.  (If you have copied
	// some bytes, return what you have instead of yielding.)
	// If the pipe is empty and closed and you didn't copy any data out, return 0.
	// Use _pipe_is_closed to check whether the pipe is closed.
	int i;
	struct Pipe *p;
	char *rbuf;

	/* Exercise 6.1: Your code here. (2/3) */

	user_panic("pipe_read not implemented");
}

static int pipe_write(struct Fd *fd, const void *vbuf, u_int n, u_int offset) {
	// Your code here.  See the lab text for a description of what
	// pipe_write needs to do.  Write a loop that transfers one byte
	// at a time.  Unlike in read, it is not okay to write only some
	// of the data.  If the pipe fills and you've only copied some of
	// the data, wait for the pipe to empty and then keep copying.
	// If the pipe is full and closed, return 0.
	// Use _pipe_is_closed to check whether the pipe is closed.
	int i;
	struct Pipe *p;
	char *wbuf;

	/* Exercise 6.1: Your code here. (3/3) */

	user_panic("pipe_write not implemented");

	return n;
}

int pipe_is_closed(int fdnum) {
	struct Fd *fd;
	struct Pipe *p;
	int r;

	if ((r = fd_lookup(fdnum, &fd)) < 0) {
		return r;
	}
	p = (struct Pipe *)fd2data(fd);
	return _pipe_is_closed(fd, p);
}

static int pipe_close(struct Fd *fd) {
	syscall_mem_unmap(0, (void *)fd2data(fd));
	syscall_mem_unmap(0, fd);
	return 0;
}

static int pipe_stat(struct Fd *fd, struct Stat *stat) {
	return 0;
}
