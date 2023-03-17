t = int(input())
s=set()
for i in range(t):
    s.add(input().lower().replace('-',' '))
print(len(s))