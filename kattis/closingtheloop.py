t = int(input())
for i in range(t):
    b=[]
    r=[]
    input()
    for j in input().split(" "):
        if j[-1] == 'B':
            b.append(int(j[:-1]))
        else:
            r.append(int(j[:-1]))
    b.sort(key=lambda x: -x)
    r.sort(key=lambda x: -x)
    idx =0
    out =0
    while (idx<len(b) and idx < len(r)):
        out +=b[idx] + r[idx]
        out -= 2
        idx+=1
    print(f"Case #{i+1}: {out}")