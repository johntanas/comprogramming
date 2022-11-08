i=input()
if len(i)<3:
    print(99)
elif len(i)==4:
    print(999)
else:
    if int(i)% 100<49:
        if i[0] == "1":
            print(99)
        else:
            print(str(int(i[0])-1)+"99")
    else:
        if i[0] == "1":
            print(99)
        else:
            print(i[0]+"99")