t = int(input())
while (t>0):
    n = int(input())
    d={}
    l=[]
    s=0
    m =0
    while (n>0):
        e=input()
        while True:
            if e in d:
                curr =l.pop(0)
                d.pop(curr)
            else:
                break
        l.append(e)
        m=max(m,len(l))
        d[e] = 1
        n-=1
    print(m)
    t-=1