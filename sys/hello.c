#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
 
static int  age  =25;     
static int  arr[10]={1,2,3,4,5,6,7,8,9,10};    
static int  num;

//S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH 表示age文件权限        644 （只有用户有写权限）
module_param(age, int, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

//S_IRGRP|S_IROTH 表示arr文件权限444(都是读权限)
module_param_array(arr, int, &num, S_IRUSR|S_IRGRP|S_IROTH);
 
static int helloworld_init(void)
{
    int i;
    printk("num=%d\r\n",num);
    printk("arg=%d\r\n",age);
    printk("arr:");
    for(i=0;i<10;i++){
        printk("%d ",arr[i]);
    }
	printk("helloworld_init.\n");
	return 0;
}
 
static void helloworld_exit(void)
{
	printk("helloworld_exit.\n");
}
 
module_init(helloworld_init);
module_exit(helloworld_exit);
 
 
MODULE_DESCRIPTION("simple module");
MODULE_VERSION("v1.0");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("yyy");