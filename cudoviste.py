r,c=[int(i) for i in input().split()]
out=[]
for i in range(r):
    out.append(input())
dr= [1,1,0,0]
dc=[0,1,0,1]
dat=[0,0,0,0,0]
for i in range(r-1):
    for j in range(c-1):
        cc=0
        cond =1
        for d in range(4):
            a= i+dr[d]
            b=j+dc[d]
            if out[a][b] =='#':
                cond =0
                break
            if out[a][b] == 'X':
                cc+=1
        if cond:
            dat[cc]+=1
for i in dat:
    print(i)

