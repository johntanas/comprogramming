import math
r,c=[int(i) for i in input().split()]
grid=[]
for i in range(r):
    grid.append(input())
if (r==1):
    print(eval(grid[0]))
if (r==2):
    prev=[]
    start=0
    j=0
    while j <c:
        if grid[1][j]=="/":
            prev.append(grid[1][start:j-1])
            j+=1
            start=j
            while (j<c and grid[0][j]=="_"):
                j+=1
            out =str(math.sqrt(eval(grid[1][start:j])))
            start=j
            prev.append(out)
        j+=1
    prev.append(grid[1][start:j])
    ee=""
    for line in prev:
        ee+=line
    print(int(eval(ee)))
if r==3:
    prev=[]
    start=0
    j=0
    while j <c:
        if grid[1][j]=="/":
            prev.append(grid[1][start:j-1])
            j+=1
            start=j
            while (j<c and grid[0][j]=="_"):
                j+=1
            out =str(math.sqrt(eval(grid[1][start:j])))
            start=j
            prev.append(out)
        if j<c and grid[1][j]=="=":
            prev.append(grid[1][start:j])
            start=j
            while (j<c and grid[1][j]=="="):
                j+=1
            out =str(eval(grid[0][start:j])/eval(grid[2][start:j]))
            start=j
            prev.append(out)
        j+=1
    prev.append(grid[1][start:j])
    ee=""
    for line in prev:
        ee+=line
    print(int(eval(ee)))

        
        