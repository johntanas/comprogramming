import sys
for t in sys.stdin:
    t=[int(i) for i in t.split()]
    t.sort()
    dat =[False]* (t[-1]+1)
    c=1
    for i in range(len(t)):
        for j in range(i+1,len(t)):
            if dat[t[j]-t[i]]:
                c=0
                break
            dat[t[j]-t[i]] = True
    if c:
        if sum(dat) == t[-1]:
            print("perfect")
        else:
            print("missing",end=" ")
            for i in range(1,len(dat)):
                if not dat[i]:
                    print(i,end=" ")
            print()
    else:
        print("not a ruler")