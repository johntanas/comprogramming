input()
def check(a,b):
    if a==b:
        return 1
    if a=='S':
        if  b =='R':
            return 0
        else:
            return 2
    if a =='P':
        if b == 'S':
            return 0
        return 2
    else:
        if b == 'P':
            return 0
        return 2
    
s= input()
l=[]
t=int(input())
for i in range(t):
    l.append(input())
ss="SPR"
m=0
out =0
for i in range(len(s)):
    e=[0,0,0]
    for k in range(len(ss)):
        for j in l:
            e[k]+=check(ss[k],j[i])
    m+=max(e)
    for j in l:
        out +=check(s[i],j[i])
print(out)
print(m)

