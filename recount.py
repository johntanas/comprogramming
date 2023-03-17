d={}
while True:
    s=input()
    if s == "***":
        break
    if s in d:
        d[s]+=1
    else:
        d[s] =1
m = 0
l =[]
for k,v in d.items():
    if v>m:
        l =[k]
        m=v
    elif v==m:
        l.append(k)
        m=v
if len(l)>1:
    print("Runoff!")
else:
    print(l[0])