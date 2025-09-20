import sys
input = lambda: sys.stdin.readline().rstrip()

n, r = map(int, input().split())
doors = list(map(int, input().split()))
cnt = 0
idx = n

if 0 in doors[:r]:
    for i in range(r - 1, 0, -1):
        if doors[i] == 1:
            doors[i] = 0
            cnt += 1
        r -= 1
    if doors[0] == 0:
        cnt += 1
for i in range(n - 1, r - 1, -1):
    if doors[i] == 0:
        idx = i + 1
        break
else:
    print(cnt)
    sys.exit(0)
for i in range(r, idx):
    if doors[i] == 0:
        cnt += 1
    else:
        cnt += 2
print(cnt)
