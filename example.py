import pdb,sys,os

f=open("/Users/slothsworth/Desktop/Dr. Li Research/TF Sites Data/wgEncodeAwgTfbsSydhA549MaxIggrabUniPk.narrowPeak",'r')
lf=f.readlines()
f.close()
lf=[item.strip() for item in lf]

A = []
B = []
F = []

for i in lf:
    if i[0] != '>':
        A.append(i)

A = "".join(A)
    
for j in range(len(A)-7):
    mer=A[j:j+8]
    B.append(mer)

D = {}

for i in B:
    if i not in D:
        D[i] = 1

    else:
        D[i] += 1
    
E=[]
for i in D:
    E.append([D[i],i])

E.sort(reverse=True)

for i in E:
    if "N" not in i[1]:
        F.append(i)

F=F[0:100]

G=""
        
f=open("/Users/slothsworth/Desktop/exampleoutput.txt", 'w')

for i in F:
    i[0]=str(i[0])
    i = "   ".join(i)
    G+=i+"\n"
f.write(G)
f.close()
    
             
