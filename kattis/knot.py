input()
s=set(i for i in input().split(" "))
for i in input().split():
    s.remove(i)
print([i for i in s][0])