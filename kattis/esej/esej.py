def toword(i):
    w=""
    while (i>0):
        w+= chr(i%26+97)
        i = i//26
    print(w,end=" ")
a,b=[int(i) for i in input().split()]
for i in range(1,b+1):
    toword(i)