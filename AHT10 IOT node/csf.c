#include <linux/module.h>
#include <linux/init.h>

static int __init csf_module_init(void)
{
    printk(KERN_INFO "Hello CSF \n");
    return 0;
}

static void __exit csf_module_exit(void)
{
    printk(KERN_INFO "GoodBye CSF \n");
}

module_init(csf_module_init);
module_exit(csf_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CSF");