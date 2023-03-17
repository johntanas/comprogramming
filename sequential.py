

n,p=map(int, input().split())
l=[int(i) for i in input().split()]
input()
out=max(l)*(p-1)+sum(l)
print(out)