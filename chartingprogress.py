import sys

total = 0
for line in sys.stdin:
    if line == '\n':
        total = 0
        print()
    else:
        n = line.count('*')
        cc = len(line) -1
        print('.'*(cc-total-n)+n*'*'+total*'.')
        total+=n