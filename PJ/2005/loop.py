from decimal import *
sss=input().split()
n=int(sss[0])
k=int(sss[1])
l=1
q=n
p=0; r=0; 
m=10**(k+1)
for i in range(1,k+1):
    p=n; r=1
    found=False
    for j in range(1,11): //注意
        p*=q
        p%=m
        r*=q
        r%=m
        if(p%(10**i)==n%(10**i)):
            l*=j
            q=r
            found=True
            break
    if(found==False):
        print(-1)
        exit(0)
print(l)
