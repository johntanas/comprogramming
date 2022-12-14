n=int(input())
idx=0
s=input()
c=1
for i in range(1,n):
    if i>9:
        if i != int(s[idx:idx+2]):
            print(i)
            c=0
            break
        idx+=2
    else:
        if i != int(s[idx:idx+1]):
            print(i)
            c=0
            break
        idx+=1
if c:
    print(n)