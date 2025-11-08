import sys
input = lambda: sys.stdin.buffer.readline()#.decode("ascii").rstrip()
fastprint = lambda s: sys.stdout.write(str(s) + "\n")
exit = lambda: sys.exit(0)

x = int(input())
n = int(input())
weight = [0] + list(map(int, input().split()))
q = int(input())
attached = set()
for _ in range(q):
    p = int(input())
    if p not in attached:
        attached.add(p)
        x += weight[p]
    else:
        attached.remove(p)
        x -= weight[p]
    fastprint(x)
