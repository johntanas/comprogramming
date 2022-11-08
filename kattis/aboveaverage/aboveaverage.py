m=int(input())
while (m>0):
    line=input().split(" ")
    n=int(line[0])
    average=0
    for i in line[1:]:
        average+=int(i)
    average=average/n
    above=0
    for i in line[1:]:
        if int(i)>average:
            above+=1
    print("{:.3f}%".format(above/n*100))
    m-=1
