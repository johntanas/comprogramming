input()
t =int(input())
d={}
for i in range(t):
    d[i] = input()
d2={}
for z,v in d.items():
    m=0
    l =v.split(", ")
    for k,vv in d.items():
        cost =0
        r = vv.split(", ")
        for i in range(len(l)):
            if l[i] !=r[i]:
                cost +=1
        m = max(m,cost)
    d2[z] = m
m=999
l=[]
for k,v in d2.items():
    if v<m:
        l=[k]
        m=v
    elif v==m:
        l.append(k)
for i in l:
    print(d[i])
