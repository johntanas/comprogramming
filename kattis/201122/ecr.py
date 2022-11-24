n,k =map(int,input().split())
n-=1
if k>n:
    print(n)
else:
    cur =k
    c =k
    if n//k != 1:
        c +=1
        cur = k *(n//k)
    print(c+n-cur)