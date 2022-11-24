t =int(input())
while t>0:
    e, i = input().split(" ")
    print(e,end=" ")
    i = int(i)
    l =[]
    while i>1:
        if i%2 == 0:
            l.append(0)
        else:
            l.append(1)
        i=i//2
    p,q =1,1
    for i in l[::-1]:
        if i:
            p  =p+q
        else:
            q = p+q
    print(str(p)+"/"+str(q))
    t-=1