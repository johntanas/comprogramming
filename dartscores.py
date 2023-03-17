n=int(input())
c=1
for i in range(21):
    for j in range(21):
        for k in range(21):
            if c:
                if i*3 +j*3+k*3 == n:
                    if i:
                        print(f"triple {i}")
                    if j:
                        print(f"triple {j}")
                    if k:
                        print(f"triple {k}")
                    c=0
                    break
                if i*3 +j*3+k*2 == n:
                    if i:
                        print(f"triple {i}")
                    if j:
                        print(f"triple {j}")
                    if k:
                        print(f"double {k}")
                    c=0
                    break
                if i*3 +j*3+k*1 == n:
                    if i:
                        print(f"triple {i}")
                    if j:
                        print(f"triple {j}")
                    if k:
                        print(f"single {k}")
                    c=0
                    break
                if i*3 +j*1+k*2 == n:
                    if i:
                        print(f"triple {i}")
                    if j:
                        print(f"single {j}")
                    if k:
                        print(f"double {k}")
                    c=0
                    break
                if i*2 +j*1+k*2 == n:
                    if i:
                        print(f"double {i}")
                    if j:
                        print(f"single {j}")
                    if k:
                        print(f"double {k}")
                    c=0
                    break
                if i*2 +j*2+k*2 == n:
                    if i:
                        print(f"double {i}")
                    if j:
                        print(f"double {j}")
                    if k:
                        print(f"double {k}")
                    c=0
                    break
if c:
    print("impossible")