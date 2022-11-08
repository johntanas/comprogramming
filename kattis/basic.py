s,t = input().split(" ")
ints=[int(i) for i in input().split(" ")]
ints.sort()
d={}
for i in ints:
    if i in d:
        d[i] +=1
    else:
        d[i] =1
def fun(t,ints,d):
    if t== '1':
        for k in d.keys():
            if 7777-k in d:
                return "Yes"
        return "No"
    if t == '2':
        for k,v in d.items():
            if v != 1:
                return "Contains duplicate"
        return  "Unique"
    if t =='3':
        for k,v in d.items():
            if v>len(ints)/2:
                return k
        return -1
    if t =='4':
        if len(ints) %2 ==1:
            return ints[int(len(ints)/2)]
        else:
            return str(ints[int(len(ints)/2)-1])+" "+str(ints[int(len(ints)/2)])
    else:
        curr =""
        for i in ints:
            if i>999:
                break
            if i>99:
                curr+=" "
                curr+=str(i)
        return curr.strip()
print(fun(t,ints,d))