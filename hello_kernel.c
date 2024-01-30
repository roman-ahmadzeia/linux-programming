#include <linux/init.h> 
#include <linux/module.h> // helps use functions like insmod lsmod etc
#include <linux/kernel.h> // this library is used for input / output 

MODULE_LICENSE("GPL");

static int __init myinit_func(void) 
// __init tells module_init that it has to insert it into kernel
// good practie to put void into param if empty
{
	printk(KERN_ALERT "Kernel Testing \n");// using printk instead of printf because we are trying to add things to kernel
	// kernel has its own console to show its messages, so if u use printf you tring
	//to use terminal not kernels console, use printk
	// the KERN_ALERT is a flag that tells kernel to show the message as a alert or warning
	// it will then log the message into the system logs
	return 0;


}

static void __exit myexit_func(void)
{
	printk(KERN_ALERT "Removing Kernel \n");

}

module_init(myinit_func);
module_exit(myexit_func);

