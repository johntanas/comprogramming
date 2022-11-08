input()
e=input().split(" ")
s=[]
for i in e:
    if len(s)>0 and (s[len(s)-1]+int(i))%2 == 0:
        s.pop()
    else:
        s.append(int(i))
print(len(s))