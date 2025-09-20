import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
solve = defaultdict(int)
order = []
for _ in range(k):
    a, b = map(int, input().split())
    solve[a] += 1
    if solve[a] == m:
        order.append(a)

print(*order)
