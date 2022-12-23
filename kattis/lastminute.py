a1,b1,a2,b2=[int(i) for i in input().split()]
out=a2*b2
if b2:
    out+=a1
if a2:
    out+=b1
if not a2 and not b2:
    out+=min(a1,b1)
print(out)