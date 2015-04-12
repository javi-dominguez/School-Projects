"""
Javier Dominguez

This Program takes in .broadPeak or .narrowPeak data, looks at beginning and end
positions of genome sequences and changes ones peak length to at least 800.

"""

import pdb,sys,os

f=open("/Users/slothsworth/Desktop/Dr. Li Research/TF Sites Data/wgEncodeAwgTfbsSydhA549MaxIggrabUniPk.narrowPeak",'r')
lf=f.readlines()
f.close()
lf=[item.strip() for item in lf]
lf=[item.split("\t") for item in lf]



i = 0
      
while i < len(lf):
    if lf[i][3] == "" or lf[i][3] == ".":
        x = lf[i][2]
    else:
        x = lf[i][3]
    y = lf[i][1]
    lf[i].append(str(int(x)-int(y)))
    i += 1

lf.sort()


f=open("/Users/slothsworth/Desktop/exampleoutput.txt", 'w')

G=""

for i in lf:
    i[0]=str(i[0])
    i = "\t".join(i)
    G+=i+"\n"
f.write(G)
f.close()


