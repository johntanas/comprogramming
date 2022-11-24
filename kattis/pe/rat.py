t =int(input())
while t>0:
    e, i = input().split(" ")
    print(e,end=" ")
    p,q = [int(i) for i in i.split("/")]
    s=1
    l =[]
    while (p != q):
        if p>q:
            p=p-q
            l.append(0)
        else:
            q = q-p
            l.append(1)
    for i in l[::-1]:
        s*=2
        if not i:
            s+=1
    print(s)
    t-=1