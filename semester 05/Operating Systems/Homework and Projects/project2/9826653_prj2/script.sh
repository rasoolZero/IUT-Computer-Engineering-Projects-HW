echo '### Making Module'
make
echo '### Installing module'
insmod mymodule.ko
echo '### Making node'
major=$(cat /proc/devices | grep mymodule | tr -dc '0-9')
mknod /dev/iutnode c $major 1
echo '### Running test'
python2 test.py
echo '### Removing Node'
rm /dev/iutnode
echo '### Removing module'
rmmod mymodule
echo '### Cleaning'
make clean
