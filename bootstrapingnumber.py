n=int(input())
m=1
for i in range(20):
    if i**i>n:
        break
    m=i
m=m //1
for i in range(1,7):
    for j in range(9):
        e=m+ 10**(-i)
        if e**e>n:
            continue
        m=e
print(m)
