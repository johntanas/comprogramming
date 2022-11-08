cond =True
while (True):
    l =0
    r=0
    t =int(input())
    if t == 0:
        break
    if cond:
        cond =False
    else:
        print()
    for j in range(t):
        curr = [i for i in input().split(" ")]
        curr[1] = int(curr[1])
        if curr[0] =="DROP":
            l+=int(curr[1])
            print(f"DROP 2 {curr[1]}")
        else:
            if r >= curr[1]:
                print(f"TAKE 1 {curr[1]}")
                r-=curr[1]
            else:
                if r!=0:
                    print(f"TAKE 1 {r}")
                    curr[1]-=r
                print(f"MOVE 2->1 {l}")
                r= l-curr[1]
                l=0
                print("TAKE 1 "+str(curr[1]))