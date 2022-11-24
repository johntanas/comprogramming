s,t = [int(i) for i in input().split()]
e=[]
while t>0:
    i =int(input())
    if i not in e:
        e.append(i)
    t-=1
for i in range(s):
    if i not in e:
        print(i)
print(f"Mario got {len(e)} of the dangerous obstacles.")