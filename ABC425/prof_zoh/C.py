import sys, math, random
import heapq
from collections import deque
input = sys.stdin.readline

n, q = map(int, input().split())
arr = [0] + list(map(int, input().split()))
pfs = [0]
for i in range(1, n + 1):
    pfs.append(pfs[-1] + arr[i])
rot = 0
for i in range(q):
    x = input().rstrip("\n").split()
    if len(x) == 2:
        rot += int(x[1])
    else:
        l, r = int(x[1]), int(x[2])
        l = (l + rot) % n
        r = (r + rot) % n
        if l == 0: l = n
        if r == 0: r = n
        if l > r:
            print(pfs[n] - pfs[l - 1] + pfs[r])
        else:
            print(pfs[r] - pfs[l - 1])
