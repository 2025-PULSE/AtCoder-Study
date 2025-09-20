import sys, math
input = sys.stdin.readline

n, q = map(int, input().split())
arr = [0] + list(map(int, input().split()))
pfs = [0 for _ in range(n + 1)]
ppfs = [0 for _ in range(n + 1)]
pppfs = [0 for _ in range(n + 1)]
lpfs = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    pfs[i] = pfs[i - 1] + arr[i]

for i in range(1, n + 1):
    ppfs[i] = ppfs[i - 1] + pfs[i]

for i in range(1, n + 1):
    pppfs[i] = pppfs[i - 1] + ppfs[i]

for l in range(1, n + 1):
    lpfs[l] = lpfs[l - 1] + l * pfs[l - 1]

for _ in range(q):
    l, r = map(int, input().split())
    fir = (r - l + 1) * ppfs[r]
    sec = (pppfs[r - 1] - pppfs[max(l - 2, 0)])

    t2 = lpfs[r] - lpfs[l - 1]
    t3 = (r + 1) * (ppfs[r - 1] - ppfs[max(l - 2, 0)])
    print(fir - sec + t2 - t3)
