obj-m := hello.o
 
#KDIR := /lib/modules/`uname -r`/build
KDIR := /lib/modules/5.13.0+/build

PWD := $(shell pwd)
 
default:
	make -C $(KDIR) M=$(PWD) modules
 
 
clean:
	rm -rf *.o *.mod.* *.ko *.symvers *.order
