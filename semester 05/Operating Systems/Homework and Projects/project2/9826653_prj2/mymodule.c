#include <linux/string.h>
#include <linux/init.h> // For module init and exit
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // For fops
#include <linux/uaccess.h>
#include <linux/kthread.h>//kernel threads
#include <linux/slab.h>
#define MAX 100
#define DEFAULT 2000000
#define SIZE 1024
#define RESET "r"

spinlock_t mylock;


char * commandPtr;
enum transactionType {enteghal,variz,bardasht,unknown};
typedef enum transactionType transactionType;
static long long accounts[MAX];

void initAccounts(void){
    int i;
    for(i=0;i<MAX;i++)
        accounts[i] = DEFAULT;
}

void mylog(const char * message){
    printk(KERN_ALERT "mymodule: %s , command:%s",message,commandPtr);
}

transactionType getType(const char *  str){
    if(!strcmp(str,"e"))
        return enteghal;
    if(!strcmp(str,"v"))
        return variz;
    if(!strcmp(str,"b"))
        return bardasht;
    return unknown;
}
int getNumber(const char * str){
    int result=-1,errorn;
    if(!strcmp(str,"-"))
        return -1;
    errorn=kstrtoint(str,10,&result);
    if(errorn!=0)
        mylog("error while parsing the numbers");
    return result;
}
void _bardasht(int from,int amount){
    if(from < 0 || from >= MAX)
        mylog("invalid account number");
    else if(amount > accounts[from])
        mylog("not enough money to withdraw");
    else
        accounts[from]-=amount;
}
void _variz(int to,int amount){
    if(to < 0 || to >= MAX)
        mylog("invalid account number");
    else
        accounts[to]+=amount;
}
void _enteghal(int from,int to,int amount){
    if(from < 0 || from >= MAX || to < 0 || to >= MAX)
        mylog("invalid account number");
    else if(amount > accounts[from])
        mylog("not enough money to withdraw");
    else{
        accounts[from] -= amount;
        accounts[to] +=amount;
    }
        
}
void runCommand(transactionType type,int from,int to,int amount){
    if(type==bardasht)
        _bardasht(from,amount);
    else if(type==variz)
        _variz(to,amount);
    else if(type==enteghal)
        _enteghal(from,to,amount);
    else
        mylog("invalid request");
}

int invalidCommand(transactionType type,int from,int to){
    return  (type==enteghal && (from==-1 || to==-1)) ||
            (type==bardasht && (from==-1 || to!=-1)) ||
            (type==variz    && (from!=-1 || to==-1));
}
void parseCommand(const char * command){
    char * section=NULL;
    int sectionCounter ,from,to,amount;
    transactionType type;
    char * copyPointer = (char *)kzalloc(sizeof(command)*sizeof(char),GFP_KERNEL);
    strcpy(copyPointer,command);
    sectionCounter = 0;
    
    while((section = strsep(&copyPointer, ","))!=NULL){
        if(sectionCounter==0)
            type = getType(section);
        if(sectionCounter==1)
            from = getNumber(section);
        if(sectionCounter==2)
            to = getNumber(section);
        if(sectionCounter==3)
            amount = getNumber(section);
        sectionCounter++;
    }
    kfree(copyPointer);
    if(sectionCounter!=4 || invalidCommand(type, from, to))
        mylog("invalid syntax for command (seperate using 3 commas)");
    else
        runCommand(type,from,to,amount);
}

void receiveCommand(const char * command){
    if(!strcmp(command,RESET))
        initAccounts();
    else
        parseCommand(command);
}

char * getAccountDetails(void){
    static char str [SIZE] = "";
    int i;
    char buffer [10];
    memset(str, 0, SIZE);
    for(i=0;i<MAX;i++){
        sprintf(buffer,"%lld,",accounts[i]);
        strcat(str, buffer);
    }
    return str;
}




















#define DEVICE_NAME "mymodule"
MODULE_LICENSE("GPL");

// FILE OPERATIONS
static int myopen(struct inode*, struct file*);
static int myrelease(struct inode*, struct file*);
static ssize_t myread(struct file*, char*, size_t, loff_t*);
static ssize_t mywrite(struct file *, const char __user *, size_t count, loff_t *);


static struct file_operations fops = {
   .open = myopen,
   .read = myread,
   .release = myrelease,
   .write=mywrite,
};

// Why "static"? --> To bound it to the current file.
static int major; // Device major number. Driver reacts to this major number.

// Event --> LOAD
static int __init myinit(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops); // 0: dynamically assign a major number ||| name is displayed in /proc/devices ||| fops.
    if (major < 0) {
        printk(KERN_ALERT "mymodule load failed.\n");
        return major;
    }
    printk(KERN_INFO "mymodule module loaded: %d\n", major);
    initAccounts();
    spin_lock_init(&mylock);
    return 0;
}

// Event --> UNLOAD
static void __exit myexit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "mymodule module unloaded.\n");
}

// Event --> OPEN
static int myopen(struct inode *inodep, struct file *filep) {
   printk(KERN_INFO "mymodule opened.\n");
   return 0;
}

// Event --> CLOSE
static int myrelease(struct inode *inodep, struct file *filep) {
   printk(KERN_INFO "mymodule closed.\n");
   return 0;
}

// Event --> READ
static ssize_t myread(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    char *message = getAccountDetails();
    int errors = 0;
    errors = copy_to_user(buffer, message, strlen(message));
    return errors == 0 ? strlen(message) : -EFAULT;
}

static ssize_t mywrite(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
    size_t maxdatalen = 100, ncopied;
    char command[maxdatalen];

    if (count < maxdatalen) 
        maxdatalen = count;

    ncopied = copy_from_user(command, buf, maxdatalen);

    if (ncopied != 0) {
        printk(KERN_ALERT "mymodule: Could't copy %zd bytes from the user\n", ncopied);
    }

    command[maxdatalen] = 0;
    
    
    commandPtr=command;
    spin_lock(&mylock);
    receiveCommand(command);
    spin_unlock(&mylock);
    return count;
}

// Registering load and unload functions.
module_init(myinit);
module_exit(myexit);
