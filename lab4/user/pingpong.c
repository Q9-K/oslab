// Ping-pong a counter between two processes.
// Only need to start one of these -- splits into two with fork.

#include <lib.h>

int main() {
	u_int who, i;

	if ((who = fork()) != 0) {
		// get the ball rolling
		debugf("\n@@@@@send 0 from %x to %x\n", syscall_getenvid(), who);
		ipc_send(who, 0, 0, 0);
		// user_panic("&&&&&&&&&&&&&&&&&&&&&&&&m");
	}

	for (;;) {
		debugf("%x am waiting.....\n", syscall_getenvid());
		i = ipc_recv(&who, 0, 0);

		debugf("%x got %d from %x\n", syscall_getenvid(), i, who);

		// user_panic("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		if (i == 10) {
			return 0;
		}

		i++;
		debugf("\n@@@@@send %d from %x to %x\n", i, syscall_getenvid(), who);
		ipc_send(who, i, 0, 0);

		if (i == 10) {
			return 0;
		}
	}
	return 0;
}
