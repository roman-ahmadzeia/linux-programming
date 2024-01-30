#include <linux/init.h> 
#include <linux/module.h> // helps use functions like insmod lsmod etc
#include <linux/kernel.h> // this library is used for input / output 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roman Ahmad Zeia");
MODULE_DESCRIPTION("100821974");

static int __init mymodule_init(void) {
    pr_info("Welcome to System Programming\n");
    return 0;
}

static void __exit mymodule_exit(void) {
    pr_info("Cleaning up the Kernel Module\n");
}

module_init(mymodule_init);
module_exit(mymodule_exit);