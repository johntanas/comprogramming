n,p =map(int,input().split())
c=1
s=set()
for i in range(n):
    t =tuple(int(i) for i in input().split())
    if (t[0],t[1]-1) in s and  (t[0],t[1]-2) in s and c:
        print(max(i-p+1,1))
        c=0
    if (t[0],t[1]-1) in s and  (t[0],t[1]+1) in s and c:
        print(max(i-p+1,1))
        c=0
    if (t[0],t[1]+1) in s and  (t[0],t[1]+2) in s and c:
        print(max(i-p+1,1))
        c=0
    s.add(t)
if c:
    print("neibb")