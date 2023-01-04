import sys
k,v= input().split()
def cal(a):
    return sum(ord(i)-ord('!')+1 for i in a)
k=cal(k)-ord(v)+ord('a')
d={'0':' ','<':',','>':'.'}

for line in sys.stdin:
    l=line.strip().split()
    out=[]
    for i in l:
        if i in d:
            out.append(d[i])
        else:
            out.append(chr((cal(i)-k)%26+ord('a')))
    for i in out:
        print(i,end="")
    print()

