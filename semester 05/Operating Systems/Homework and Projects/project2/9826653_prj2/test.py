import os,random,threading

def routine(fd):
    for i in range(1000000):
        randomAccount = random.randrange(1,100)
        command = "e,{0},0,1".format(randomAccount)
        os.write(fd,command)



path = "/dev/iutnode"
fd = os.open(path, os.O_RDWR)
print("\n## Python Test: # Account Balance: ")
os.write(fd,"r")
data = os.read(fd, 1024)
print(data.decode())
print("\n## Python Test: # operation started ...")
t1 = threading.Thread(target=routine,args=(fd,))
t2 = threading.Thread(target=routine,args=(fd,))
t1.start()
t2.start()
t1.join()
t2.join()
print("\n## Python Test: # operation done ...")
data = os.read(fd, 1024)
print(data.decode())
os.close(fd)
