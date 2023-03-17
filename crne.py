s=int(input())
if s%2==0:
    s=int(s/2+1)
    print(int(s*s))
else:
    print(int((s+1)*(s+3)/4))