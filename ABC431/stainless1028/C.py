import sys
input = lambda: sys.stdin.buffer.readline()#.decode("ascii").rstrip()
fastprint = lambda s: sys.stdout.write(str(s) + "\n")
exit = lambda: sys.exit(0)

n, m, k = map(int, input().split())
h = sorted(map(int, input().split()))
b = sorted(map(int, input().split()))
cnt = 0
i, j = 0, 0
while True:
    if i >= n or j >= m:
        fastprint("YNeos"[cnt < k::2])
        exit()
    head, body = h[i], b[j]
    if head <= body:
        cnt += 1
        i += 1
        j += 1
    else:
        j += 1
