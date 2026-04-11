#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x54ca6c49, "try_module_get" },
	{ 0xcdc8910, "param_ops_uint" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x6775d5d3, "class_destroy" },
	{ 0xedc03953, "iounmap" },
	{ 0xaf56600a, "arm64_use_ng_mappings" },
	{ 0xdc0e4855, "timer_delete" },
	{ 0xcc6d90ab, "param_ops_byte" },
	{ 0x92997ed8, "_printk" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0xa916b694, "strnlen" },
	{ 0x4e51e4b4, "module_put" },
	{ 0x24d273d1, "add_timer" },
	{ 0x6e26cac4, "device_create" },
	{ 0x59c02473, "class_create" },
	{ 0xdcb764ad, "memset" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x418c10ec, "__register_chrdev" },
	{ 0x607a5c68, "device_destroy" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x40863ba1, "ioremap_prot" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2CA235C02160FFB50652C77");
