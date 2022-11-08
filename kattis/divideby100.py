f = input()
s = input()
e=len(s)
d = len(f)
if e>d:
    print("0.",end="")
    e-=1
    while (e>d):
        print("0",end="")
        e-=1
    curr = ""
    for i in f:
        curr+=i
        if i != "0":
            print(curr,end="")
            curr =""
else:
    curr =""
    for i in f:
        if d==e-1:
            print(curr,end="")
            curr =""
            curr+="."
        curr+=i
        if i != "0":
            print(curr,end="")
            curr =""
        d-=1