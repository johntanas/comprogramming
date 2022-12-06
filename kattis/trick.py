s=input()
if len(s) == len(set(i for i in s)):
    print(1)
else:
    print(0)