import sys

for e in sys.stdin:
    e=int(e)
    out=1
    c=1
    while (out%e!=0):
        out*=10
        out+=1
        c+=1
        out%=e
    print(c)