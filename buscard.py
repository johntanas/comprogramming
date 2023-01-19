n=int(input())
out=0
while (n>500):
    n-=500
    out+=1
if n<200 or n>400:
    print(out+1)
else:
    print(out+2)