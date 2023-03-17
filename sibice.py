n,w,h =map(int,input().split())
cc=0
for i in range(n):
    c =int(input())
    if c<= w or c<=h or c**2<=w**2+h**2:
        print("DA")
        cc+=1
    else:
        print("NE")
