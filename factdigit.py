t=int(input())
for i in range(t):
    a= int(input())
    aa=1
    for j in range(1,a+1):
        aa*=j
    print(str(aa)[-1])