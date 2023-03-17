s=int(input())
m=100001
d={i:i for i in range(m)}
for i in range(m):
    for j in range(1,i+1):
        if len(str(j)+str(i))>6:
            break
        curr=int(str(j)+str(i))
        if curr <m:
            d[curr] = min(d[j] +d[i],d[curr])
        curr=int(str(i)+str(j))
        if curr <m:
            d[curr] = min(d[j] +d[i],d[curr])
        curr=i+j
        if curr <m:
            d[curr] = min(d[j] +d[i],d[curr])
    n=1
    while (n<=i):
        curr=n*i
        if curr <m:
            d[curr] = min(d[i] +d[n],d[curr])
        else:
            break
        n+=1
    add=1
print(d[s])
