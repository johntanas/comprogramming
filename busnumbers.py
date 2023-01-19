n=int(input())
l=[int(i) for i in input().split()]
l.sort()
pre=-1
idx=0
while (idx<n):
    out=[l[idx]]
    while (idx<n-1 and l[idx+1]==l[idx]+1):
        out.append(l[idx+1])
        idx+=1
    if len(out)<3:
        print(*out,end=" ")
    else:
        print(str(out[0])+"-"+str(out[len(out)-1]),end=" ")
    idx+=1