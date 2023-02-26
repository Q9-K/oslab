#include <lib.h>

int main() {
	int a = 0;
	if (fork() == 0) {
		if (fork() == 0 && fork() == 0 && fork() == 0 && fork() == 0 && fork() == 0) {
			debugf("\n\n\n!@this is child %x :a:%d\n\n\n", syscall_getenvid(), a);
		}
		return 0;
	}
	debugf("!@ancestor exit\n\n");
	return 0;
}
