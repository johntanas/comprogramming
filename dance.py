s,n = input().split(" ")
e=[]
for i in range(int(s)):
    e.append(input())
s=1
for j in range(int(n)):
    cond = True
    for i in e:
        if i[j] != "_":
            cond = False
            break
    if cond:
        s+=1
print(s)