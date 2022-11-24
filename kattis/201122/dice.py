n=int(input())
d={}
def add(d,s):
    if s in d:
        d[s] +=1
    else:
        d[s] =1
while n>0:
    l=input().split(" ")
    t,f,b = (l[0],l[1]),(l[2],l[3]),(l[4],l[5])
    add(d,(t,f,b))
    add(d,(t,b,f))
    add(d,(b,f,t))
    add(d,(f,t,b))
    n-=1
print(max(d.values()))