input()
s=[int(i) for i in input().split(" ")]
l=[]
sum=0
for i in s:
    if len(l)>0 and l[len(l)-1] == i:
        l.pop()
    else:
        l.append(i)
    sum+=1
if len(l)>0:
    print("impossible")
else:
    print(sum)