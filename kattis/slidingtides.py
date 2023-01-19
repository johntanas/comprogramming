d={}
while (True):
    n=int(input())
    if (n==-1):
        break
    n+=1
    grid=[[0]*(5+2*n) for _ in range(5+2*n)]
    for i in range(0,5):
        for j in range(0,5):
            grid[i+n][j+n]=chr(65+i*5+j)
            d[chr(65+i*5+j)]=(i+n,j+n)
    n-=1
    for i in range(n):
        l,cmd=input().split()
        r,c=d[l]
        t=l
        grid[r][c]=0
        if cmd=="up":
            while (t!=0):
                t=grid[r-1][c]
                grid[r-1][c]=l
                d[l]=(r-1,c)
                l=t
                r-=1
        if cmd=="down":
            while (t!=0):
                t=grid[r+1][c]
                grid[r+1][c]=l
                d[l]=(r+1,c)
                l=t
                r+=1
        if cmd=="right":
            while (t!=0):
                t=grid[r][c+1]
                grid[r][c+1]=l
                d[l]=(r,c+1)
                l=t
                c+=1
        if cmd=="left":
            while (t!=0):
                t=grid[r][c-1]
                grid[r][c-1]=l
                d[l]=(r,c-1)
                l=t
                c-=1
    rmi=cmi=5+2*n
    rma=cma=0
    for v in d.values():
        r,c=v
        rmi=min(r,rmi)
        cmi=min(c,cmi)
        rma=max(r,rma)
        cma=max(c,cma)
    out=[]
    for i in range(rmi,rma+1):
        line =""
        buf =""
        for j in range(cmi,cma+1):
            if grid[i][j]:
                buf+=grid[i][j]
                line+=buf
                buf=""
            else:
                buf+=" "
        out.append(line)
    for line in out:
        print(line)
    print()