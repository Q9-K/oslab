extern char bss_end[];
void mips_init() {
	if ((u_long)mips_init < KERNBASE || (u_long)mips_init >= KSTACKTOP) {
		panic("bad address of kernel code: %x", mips_init);
	}
	if ((u_long)bss_end < KERNBASE || (u_long)bss_end > KSTACKTOP) {
		panic("bad address of bss_end: %x", (u_long)bss_end);
	}

	printk_1_check();
	printk_2_check();
	printk_3_check();
	halt();
}
