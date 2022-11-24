n =int(input())
d={}
for i in range(n):
    c = input()
    if c in d:
        d[c].append(i)
    else:
        d[c]=[i]
s =0
pm=-1
m=-1
while (m<n-1):
    s+=1
    m=-1
    for v in d.values():
        while v:
            if len(v) ==0 or v[0]>pm:
                break
            v.pop(0)
        if len(v)>0:
            m = max(m,v[0])
    pm =m
print(s)