"""
Javier Dominguez

This Program compares a preprocessed OCR file and a preprocessed TF file to find
overlaps between two start and end peak points.

"""
import pdb,sys,os,re
##Opening extended OCR Peak Data.
f=open("//Users/slothsworth/Dropbox/OCR ChIP-Seq Data/OCR Data/A549-DS14289_ocr_extended.txt",'r')

lf=f.readlines()
f.close()
lf=[item.strip() for item in lf]
lf=[item.split(" ") for item in lf]
lf.sort()

##Opening A549 CHIP-Seq Extended Data.  
f=open("/users/slothsworth/Desktop/extendedA549.txt",'r')
tf=f.readlines()
f.close()
tf=[item.strip() for item in tf]
tf=[item.split() for item in tf]
tf.sort()


def overlap(start1, end1, start2, end2):
    return end1 >= start2 and end2 > start1

def set_dict(x, dx):
    i = 0
    bounded = []
    while i < len(x)-1:
        if (x[i][0] == x[i+1][0]) == True:
            bounded += [[x[i][1],x[i][2], x[i][3]]]
            dx[x[i][0]] = bounded
        if (x[i][0] == x[i+1][0]) == False:
            bounded = []
        i+=1
    return

## Setting LF in dictionary by chromosome as key.
dlf = {}
set_dict(lf,dlf)
for key in dlf:
    dlf[key]=sorted(dlf[key],key=lambda X:X[0])
   
op1 = {}
op2 = {}
placeholder_for_bounded = []
placeholder_for_unbounded = []
op4 = {}

## Setting TF in dictionary by chromosome as key.
dtf = {}
set_dict(tf,dtf)
for key in dtf:
    dtf[key]=sorted(dtf[key],key=lambda X:X[0])
    

for key in dlf:
        i = 0
        j = 0
        if (key in dtf) == (key in dlf) is True:
            while i < len(dlf[key])-1:
                while j < len(dtf[key])-1:
                    if (dlf[key][i][1] < dtf[key][j][0]) is True:
                       ### placeholder_for_unbounded += [dlf[key][i][0],dlf[key][i][1], dtf[key][j][0], dtf[key][j][1]]
                        j+=1
                    if (dlf[key][i][0] > dtf[key][j][1]) is True:
                       ### placeholder_for_unbounded += [dlf[key][i][0],dlf[key][i][1], dtf[key][j][0], dtf[key][j][1]]
                        j+=1
                    if overlap(dlf[key][i][0], dlf[key][i][1], dtf[key][j][0], dtf[key][j][1]) == True:
                        placeholder_for_bounded += [dlf[key][i][0],dlf[key][i][1], dtf[key][j][0], dtf[key][j][1]]
                        j+=1
                    else:
                        placeholder_for_unbounded += [dlf[key][i][0],dlf[key][i][1], dtf[key][j][0], dtf[key][j][1]]
                        j+=1
                i+=1
                j=0
            op2[key] = placeholder_for_unbounded
            op1[key] = placeholder_for_bounded
    

f=open("/users/slothsworth/Desktop/boundedpeaks.txt", 'w')
J="OVERLAPS: "+str(len(op1))+"\n"
G=""
for key in op1:
    i = 0
    while i < len(op1[key]):
        G+=key+"\t"+str(op1[key][i])+"\n"
        i+=1


        
f.write(G)
f.write(J)
f.close()

f=open("/users/slothsworth/Desktop/unboundedpeaks.txt", 'w')
H=""
L="OVERLAPS: "+str(len(op2))+"\n"
for key in op2:
    i = 0
    while i < len(op2[key]):
        H+=key+"\t"+str(op2[key][i])+"\n"
        i+=1

f.write(H)
f.write(L)
f.close()




