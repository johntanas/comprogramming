n,s = input().split(" ")
n=int(n)
idx=0
for i in s:
    if i =="L":
        idx=idx*2+1
    else:
        idx=idx*2+2
print(2**(n+1)-idx-1)