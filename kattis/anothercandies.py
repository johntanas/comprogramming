t=int(input())
for i in range(t):
    input()
    n=int(input())
    out=0
    for j in range(n):
        out+=int(input())
    if out%n:
        print("NO")
    else:
        print("YES")