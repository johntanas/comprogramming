for i in range(int(input())):
    l=input().split()
    if len(l)<3:
        print()
    elif l[0]=="simon" and l[1]=="says":
        print(*l[2:])
    else:
        print()