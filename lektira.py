a=input()
d=a
for i in range(0,len(a)+1):
    for j in range(i+1,len(a)+1):
        e=a
        if a[i::-1] and a[j:i:-1] and a[:j:-1]:
            e=a[i::-1]+a[j:i:-1]+a[:j:-1]
        if e<d:
            d=e
print(d)