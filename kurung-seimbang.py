import sys

t = int(next(sys.stdin))

for _ in range(t):
    s = sys.stdin.readline().rstrip('\n')
    brackets = ['()', '{}', '[]']
    while any(x in s for x in brackets):
        for br in brackets:
            s = s.replace(br, '')
    if(not s):
        print(1)
    else:
        print(0)


