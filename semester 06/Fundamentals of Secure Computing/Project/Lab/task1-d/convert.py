#!/usr/bin/env python3

# Run "xxd -p -c 20 rev_sh.o",
# copy and paste the machine code to the following:
ori_sh ="""
31c0506831323334
686161613d89e3506835363738686262623d89e1
ba34787878c1e218c1ea1852683d313233686363
636389e25053515289e250682f656e76682f6269
6e682f75737289e3505389e131c0b00bcd80
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


