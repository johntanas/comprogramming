t =int(input())
p=0
s=1
for i in range(t):
    e=int(input())
    if e>p:
        p=e
    else:
        p=e
        s+=1
print(s)