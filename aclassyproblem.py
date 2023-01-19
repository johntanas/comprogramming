t=int(input())
for i in range(t):
    n=int(input())
    out=[]
    for j in range(n):
        l=input().split()
        name=l[0][:len(l[0])-1]
        clas=l[1].split("-")
        rank=[]
        for k in clas[::-1]:
            if (k=="upper"):
                rank.append(-3)
            elif (k=="middle"):
                rank.append(-2)
            else:
                rank.append(-1)
        while (len(rank)<10):
            rank.append(-2)
        out.append((rank,name))
    out.sort()
    for i in out:
        print(i[1])
    print("==============================")