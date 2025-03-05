import os
path = "/dev/iutnode"
fd = os.open(path, os.O_RDONLY)
data = os.read(fd, 128)
print(f'Number of bytes read: {len(data)}')
print(data.decode())
os.close(fd)