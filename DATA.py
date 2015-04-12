"""
Javier Dominguez

This program takes in two input sources: OCR peaks and CHIP-Seq peaks. It will then compare overlaps
and output two files, one for overlaps (bounded regions) and ones without overlaps (unbounded regions).


"""

import pdb,sys,os

f=open('/home/jdominguez/Desktop/OCR CHIP-Seq Data/A549-DS14289_ocr_extended.txt','r')
lf=f.readlines()
f.close()

"""
lf=[item.strip() for item in lf]
lf=[item.split("\t") for item in lf]





lf.sort()
"""

"""
f=open("/Users/slothsworth/Desktop/exampleoutput.txt", 'w')

G=""

for i in lf:
    i[0]=str(i[0])
    i = "\t".join(i)
    G+=i+"\n"
f.write(G)
f.close()
""""

