lc =1
while True:
    t=int(input())
    if t==0:
        break
    print(f"List {lc}:")
    d={}
    for i in range(t):
        e=input().split(" ")[-1]
        e=e.lower()
        if e in d:
            d[e] +=1
        else:
            d[e] =1
    l=[]
    for k,v in d.items():
        l.append((k,v))
    l.sort(key=lambda x: x[0])
    for k,v in l:
        print(str(k)+" | "+str(v))
    lc+=1