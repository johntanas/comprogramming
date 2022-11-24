l,k = input().split(" ")
k=int(k)
if len(l)/2>=k:
    print("Yes")
else:
    d= [i for i in l]
    e =d.copy()
    d.sort()

    if d[len(d)-k:k] == e[len(d)-k:k]:
        print("Yes")
    else:
        print("No")