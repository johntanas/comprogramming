t =int(input())
ll=[]
for i in range(t):
    l =input().split()
    if l[0].isdigit():
        ll.append((int(l[0])/2,l[1]))
    else:
        ll.append((int(l[1]),l[0]))
ll.sort(key = lambda x: (x[0],x[1]))
for i in ll:
    print(i[1])