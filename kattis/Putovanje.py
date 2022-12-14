n,c =map(int,input().split())
l=[int(i) for i in input().split()]
m=0
for i in range(len(l)):
    cc=0
    cal =0
    while (i<len(l)):
        if cal +l[i] >c:
            i+=1
            continue
        else:
            cal+=l[i]
            i+=1
            cc+=1
    m=max(cc,m)
print(m)