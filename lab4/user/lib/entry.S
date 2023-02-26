#include <asm/asm.h>
#include <mmu.h>
#include <trap.h>

.data

.align 12

.globl fsipcbuf
fsipcbuf:
.space BY2PG

.text
EXPORT(_start)
	lw      a0, 0(sp)
	lw      a1, 4(sp)
	jal     libmain
