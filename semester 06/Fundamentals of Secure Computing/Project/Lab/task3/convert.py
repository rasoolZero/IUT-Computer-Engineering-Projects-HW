#!/usr/bin/env python3

# Run "xxd -p -c 20 rev_sh.o",
# copy and paste the machine code to the following:
ori_sh ="""
4831c0b06848ba2f62696e2f62617350
524889e74831d252574889e64831c0b03b0f05
"""

sh = ori_sh.replace("\n", "")

length  = int(len(sh)/2)
print("Length of the shellcode: {}".format(length))
s = 'shellcode= (\n' + '   "'
for i in range(length):
    s += "\\x" + sh[2*i] + sh[2*i+1]
    if i > 0 and i % 16 == 15: 
       s += '"\n' + '   "'
s += '"\n' + ").encode('latin-1')"
print(s)


