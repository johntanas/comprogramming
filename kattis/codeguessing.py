l = [int(i) for i in input().split()]
s=input()
out =[]
e=l.copy()
for i in range(1,10):
    if i in l:
        continue
    l.append(i)
    for j in range(i+1,10):
        if j in l:
            continue
        dd=l.copy()
        dd.append(j)
        dd.sort()
        c=True
        for i in range(4):
            if s[i] =="A":
                if dd[i] not in e:
                    c=False
                    break
            if s[i] =="B":
                if dd[i] in e:
                    c=False
                    break
        if c:
            out.append([l[-1],j])
    l=e.copy()
if (len(out)>1):
    print(-1)
else:
    ee= out[0]
    ee.sort()
    for i in ee:
        print(i,end=" ")