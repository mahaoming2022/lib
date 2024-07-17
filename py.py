from decimal import *
getcontext().prec = 100000
sss=input().split()
n=Decimal(sss[0])
k=int(sss[1])
ans=1
mul=Decimal(n)
mod=10**(k+1);
for i in range(1,k+1):
    tmp=n;f=0
    for j in range(1,11):
        tmp=tmp*mul%mod
        if(tmp%(10**i)==n%(10**i)):
            ans=ans*j;f=j
            break
    if(f==0): print("-1");exit(0);
    tmp=mul
    for j in range(1,f):
        mul=mul*tmp%mod
print(ans)