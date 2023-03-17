t=int(input())
for i in range(t):
    l=[int(i) for i in input().split()]
    x=abs(l[0]-l[2])
    y=abs(l[1]-l[3])
    out=0
    if x==y:
        out+=2*x
    elif x<y:
        out+=2*x
        y-=x
        out+=y//2*4
        out+=y%2
    else:
        out+=2*y
        x-=y
        out+=x//2*4
        out+=x%2
    print(out)