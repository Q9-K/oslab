#include <lib.h>

int main() {
	int a = 0;
	int id = 0;
	debugf("fktest on ostest!\n");
	if ((id = fork()) == 0) {
		if ((id = fork()) == 0) {
			if ((id = fork()) == 0) {
				if ((id = fork()) == 0) {
					a += 5;
					int iiiii;
					for (iiiii = 0; iiiii < 1000; iiiii++) {
						debugf("@this is child4 :a:%d\n", a);
					}
					return 0;
				}
				a += 4;
				int iiii;
				for (iiii = 0; iiii < 1000; iiii++) {
					debugf("@this is child3 :a:%d\n", a);
				}
				return 0;
			}
			a += 3;
			int i;
			for (i = 0; i < 1000; i++) {
				debugf("@this is child2 :a:%d\n", a);
			}
			return 0;
		}
		a += 2;
		int ii;
		for (ii = 0; ii < 1000; ii++) {
			debugf("@this is child :a:%d\n", a);
		}
		return 0;
	}
	a++;
	int iii;
	for (iii = 0; iii < 1000; iii++) {
		debugf("@this is father: a:%d\n", a);
	}
	debugf("@father exit\n");
	return 0;
}
