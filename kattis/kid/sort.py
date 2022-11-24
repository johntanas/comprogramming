n, c = map(int,input().split(" "))
d={}
d2={}
dix=0
for i in input().split(" "):
    if i in d:
        d[i] +=1
    else:
        d[i] =1
        d2[i] =dix
    dix+=1
l=[]
for k,v in d.items():
    l.append((v,d2[k],k))
l.sort(key = lambda x: (-x[0],x[1]))
for i in l:
    for j in range(i[0]):
        print(i[2],end =" ")
print()