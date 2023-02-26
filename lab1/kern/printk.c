#include <drivers/dev_cons.h>
#include <print.h>
#include <printk.h>
#include <trap.h>

void outputk(void *data, const char *buf, size_t len) {
	for (int i = 0; i < len; i++) {
		printcharc(buf[i]);
	}
}

void printk(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vprintfmt(outputk, NULL, fmt, ap);
	va_end(ap);
}

void print_tf(struct Trapframe *tf) {
	for (int i = 0; i < sizeof(tf->regs) / sizeof(tf->regs[0]); i++) {
		printk("$%2d = %08x\n", i, tf->regs[i]);
	}
	printk("HI  = %08x\n", tf->hi);
	printk("LO  = %08x\n\n", tf->lo);
	printk("CP0.SR    = %08x\n", tf->cp0_status);
	printk("CP0.BadV  = %08x\n", tf->cp0_badvaddr);
	printk("CP0.Cause = %08x\n", tf->cp0_cause);
	printk("CP0.EPC   = %08x\n", tf->cp0_epc);
}

void printk_1_check(void) {
	printk("%5d\n", 999999);
	printk("%5d\n", 12);
	printk("%5d\n", -12);
	printk("%5d\n", -1234);
	printk("%05d\n", 12);
	printk("%-5d\n", 12);
	printk("%-5d\n", -12);
	printk("%05d\n", -12);
	printk("%05b\n", -8);
	printk("%05b\n", 2147483647);
	printk("%05d\n", -100);
	printk("%05o\n", -100);
	printk("%05O\n", -100);
	printk("%05u\n", -100);
	printk("%05U\n", -100);
	printk("%05x\n", 1194684);
	printk("%05X\n", 1194684);
	printk("%05x\n", -1194684);
	printk("%05X\n", -1194684);
	int asc = 65;
	for (asc = 65; asc <= 90; asc++) {
		printk("%c", asc);
	}
	printk("\n");
	char str[] = "I love buaa scse!";
	char *strptr = str;
	printk("%s\n", str);
	printk("%c", *strptr++);
	printk("%c", *strptr++);
	printk("%c", *strptr);
	printk("\n");
}

void printk_2_check(void) {
	int a = 97;
	int b = -97;

	printk("%d\n", a);
	printk("%c\n", a);
	printk("%x\n", a);
	printk("%u\n", a);
	printk("%b\n", a);

	printk("i love buaa\n");
	printk("abcdefghijklmnopqrst\n");
	printk("i love os\n");
	printk("string\n");
	printk("good luck\n");

	printk("%dand%d\n", b, a);
	printk("%dand%c\n", b, a);
	printk("%dand%x\n", b, a);
	printk("%dand%b\n", b, a);
	printk("%dand%u\n", b, a);

	printk("%04dend\n", a);
	printk("%04xend\n", a);
	printk("%-4dend\n", a);
	printk("%-4xend\n", a);
	printk("%ldend\n", a);

	printk("%04ldend\n", a);
	printk("%04lxend\n", b);
}

void printk_3_check(void) {
	int b = 98;
	int c = -98;
	int d = 2022;

	printk("%b\n", b);
	printk("%d\n", b);
	printk("%D\n", b);
	printk("%o\n", b);
	printk("%u\n", b);
	printk("%U\n", b);
	printk("%x\n", d);
	printk("%X\n", d);

	char str[] = "printk_1";
	printk("printk_1\n");
	printk("This letter is %c\n", *str);
	printk("start- %s -end\n", str);

	printk("%d and %d\n", c, b);
	printk("%d and %c\n", c, b);
	printk("%d and %x\n", c, b);
	printk("%d and %b\n", c, b);
	printk("%d and %u\n", c, b);
}
