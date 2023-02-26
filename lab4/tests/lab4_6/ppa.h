#include <lib.h>

static void os_bye(const char *s) {
	syscall_panic(s);
}

static void uassert(int cond) {
	if (!cond) {
		os_bye("OSTEST_ERR");
	}
}

static void accepted() {
	os_bye("OSTEST_OK");
}

#define tot 22
