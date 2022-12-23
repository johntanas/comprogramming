
t=int(input())
for i in range(t):
    l,r=[int(j) for j in input().split()]
    out=1+(l+r)*(l+r+1)//2 +r
    print(out)