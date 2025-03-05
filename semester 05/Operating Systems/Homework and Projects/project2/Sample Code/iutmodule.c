#include <linux/init.h> // For module init and exit
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // For fops
#include <linux/uaccess.h>
//#include <string.h> // Can't use it!

#define DEVICE_NAME "iut_device"
MODULE_LICENSE("GPL");

// FILE OPERATIONS
static int iut_open(struct inode*, struct file*);
static int iut_release(struct inode*, struct file*);
static ssize_t iut_read(struct file*, char*, size_t, loff_t*);

static struct file_operations fops = {
   .open = iut_open,
   .read = iut_read,
   .release = iut_release,
};

// Why "static"? --> To bound it to the current file.
static int major; // Device major number. Driver reacts to this major number.

// Event --> LOAD
static int __init iut_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops); // 0: dynamically assign a major number ||| name is displayed in /proc/devices ||| fops.
    if (major < 0) {
        printk(KERN_ALERT "iut_device load failed.\n");
        return major;
    }
    printk(KERN_INFO "iut_device module loaded: %d\n", major);
    return 0;
}

// Event --> UNLOAD
static void __exit iut_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "iut_device module unloaded.\n");
}

// Event --> OPEN
static int iut_open(struct inode *inodep, struct file *filep) {
   printk(KERN_INFO "iut_device opened.\n");
   return 0;
}

// Event --> CLOSE
static int iut_release(struct inode *inodep, struct file *filep) {
   printk(KERN_INFO "iut_device closed.\n");
   return 0;
}

// Event --> READ
static ssize_t iut_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    char *message = "IUT OS project 2!";
    int errors = 0;
    errors = copy_to_user(buffer, message, strlen(message));
    return errors == 0 ? strlen(message) : -EFAULT;
}

// Registering load and unload functions.
module_init(iut_init);
module_exit(iut_exit);
