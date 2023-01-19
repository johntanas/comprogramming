for i in range(int(input())):
    a,b,c=[int(i)for i in input().split()] 
    if a+b ==c or abs(a-b) ==c or a*b ==c or a/b ==c or b/a==c:
        print("Possible")
    else:
        print("Impossible")