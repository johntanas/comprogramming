f=int(input())
s=int(input())
if f>s:
    if abs(f-s)<abs(360-f+s):
        print(s-f)
    else:
        print(360-f+s)
else:
    if abs(s-f)<=abs(-f-360+s):
        print(s-f)
    else:
        print(-f-360+s)