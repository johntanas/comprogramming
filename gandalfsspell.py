f=input()
l=input().split()
d={}
cond = True
d2={}
if len(f) != len(l):
    cond =False
for i in range(len(l)):
    if (not cond):
        break
    if l[i] in d:
        if d[l[i]] != f[i]:
            cond = False
            break
    else:
        d[l[i]] = f[i]
    if f[i] in d2:
        if d2[f[i]] != l[i]:
            cond = False
            break
    else:
        d2[f[i]] = l[i]
print(cond)