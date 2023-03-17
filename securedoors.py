t = int(input())
s=set()
for i in range(t):
    tt,n = input().split()
    if tt == "entry":
        if n in s:
            print(n+" entered (ANOMALY)")
        else:
            s.add(n)
            print(n+" entered")
    else:
        if n in s:
            print(n+" exited")
            s.remove(n)
        else:
            print(n+" exited (ANOMALY)")