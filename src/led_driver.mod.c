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
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x3c98aa3c, "__register_chrdev" },
	{ 0xfb3de43c, "class_create" },
	{ 0x773c4019, "device_create" },
	{ 0x76a97ac1, "gpio_request" },
	{ 0x2bdae3c1, "gpiod_direction_output_raw" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0x7c77f2d5, "class_destroy" },
	{ 0x89258034, "device_destroy" },
	{ 0x6a54fb52, "gpiod_set_raw_value" },
	{ 0xebe5da4a, "gpio_free" },
	{ 0x7c77f2d5, "class_unregister" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0xd272d446, "__fentry__" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x2ec37059, "gpio_to_desc" },
	{ 0xe8783260, "gpiod_get_raw_value" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xab006604, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0x3c98aa3c,
	0xfb3de43c,
	0x773c4019,
	0x76a97ac1,
	0x2bdae3c1,
	0x52b15b3b,
	0x7c77f2d5,
	0x89258034,
	0x6a54fb52,
	0xebe5da4a,
	0x7c77f2d5,
	0x092a35a2,
	0xd272d446,
	0xe8213e80,
	0xd272d446,
	0x2ec37059,
	0xe8783260,
	0x092a35a2,
	0xab006604,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__stack_chk_fail\0"
	"__register_chrdev\0"
	"class_create\0"
	"device_create\0"
	"gpio_request\0"
	"gpiod_direction_output_raw\0"
	"__unregister_chrdev\0"
	"class_destroy\0"
	"device_destroy\0"
	"gpiod_set_raw_value\0"
	"gpio_free\0"
	"class_unregister\0"
	"_copy_from_user\0"
	"__fentry__\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"gpio_to_desc\0"
	"gpiod_get_raw_value\0"
	"_copy_to_user\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D30863D1FDE21AF6EB4AABD");
