n =int(input())
l = input().split(" ")
s=[]
while True:
    cond =True
    loser =[]
    e=[]
    for i in range(len(l)):
        if i>0 and i<len(l)-1:
            if l[i-1]<=l[i] and l[i+1]<=l[i]:
                e.append(l[i])
            else:
                loser.append(l[i])
                cond =False
        elif i<len(l)-1:
            if l[i+1]<=l[i]:
                e.append(l[i])
            else:
                loser.append(l[i])
                cond =False
        else:
            if l[i-1]<=l[i]:
                e.append(l[i])
            else:
                loser.append(l[i])
                cond =False
    if cond:
        break
    l=e.copy()
    s.append(loser.copy())
print(len(s))
for i in s:
    print(*i)
print(*e)
    
    