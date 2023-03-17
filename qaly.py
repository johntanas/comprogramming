n=int(input())
s=0.0
for i in range(n):
    f,ff=map(float,input().split(" "))
    tt=f*ff
    s+= tt
print(s)