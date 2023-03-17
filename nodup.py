l=input().split()
s=set()
c= True
for i in l:
    if i in s:
        c=False
        break
    s.add(i)
if c:
    print("yes")
else:
    print('no')