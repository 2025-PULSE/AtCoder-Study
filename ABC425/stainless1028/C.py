import sys
input = lambda: sys.stdin.readline().rstrip()

"""
TLE 안당하려면 prefix sum 이용
"""

n, q = map(int, input().split())
arr = list(map(int, input().split()))

sums = [0] * n
sums[0] = arr[0]
for i in range(1, n):
    sums[i] = sums[i-1] + arr[i]

cnt = 0
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        cnt = (cnt + query[1]) % n
    else:
        l, r = query[1:]
        l = (l - 1 + cnt) % n
        r = (r - 1 + cnt) % n

        ans = 0
        if l <= r:
            if l == 0:
                ans = sums[r]
            else:
                ans = sums[r] - sums[l-1]
        else:
            ans = sums[n-1] - sums[l-1] + sums[r]
        print(ans)
