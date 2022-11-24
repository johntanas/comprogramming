sum =0
s=[int(i) for i in input().split(" ")]
e= s[0]+s[1]
if s[2] ==0:
    print(0)
else:
    while (e>=1):
        r= e% s[2]
        e=e // s[2]
        if e>=1:
            sum+=e
            e+=r
    print(sum)