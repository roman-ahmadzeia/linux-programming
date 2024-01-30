CONFIG_MODULE_SIG=n
obj-m += lab_one_kernel.o

all: 
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

