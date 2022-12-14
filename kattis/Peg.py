import sys

out=[]
for line in sys.stdin:
    out.append(line.replace("\n",""))
r =len(out)
c=len(out[0])
count =0
for i in range(r):
    for j in range(c):
        if i>=2:
            if out[i][j] =='o' and out[i-1][j] =='o' and out[i-2][j] == '.':   
                count+=1
        if i<r-2:
            if out[i][j] =='o' and out[i+1][j] =='o' and out[i+2][j] == '.':   
                count+=1
        if j<c-2:
            if out[i][j] =='o' and out[i][j+1] =='o' and out[i][j+2] == '.':   
                count+=1 
        if j>=2:
            if out[i][j] =='o' and out[i][j-1] =='o' and out[i][j-2] == '.':   
                count+=1
print(count)