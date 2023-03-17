s=input()
o=[]
d={'R':'S','B':'K','L':'H'}
ss=set(["RBL","BRL","LBR","BLR","RLB","LRB"])
idx =0
while (idx<len(s)):
    if s[idx:idx+3] in ss:
        o.append('C')
        idx+=3
    else:
        o.append(d[s[idx]])
        idx+=1
for i in o:
    print(i,end="")
print()