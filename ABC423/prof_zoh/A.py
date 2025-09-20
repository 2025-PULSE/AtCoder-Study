import sys, math
input = sys.stdin.readline

n, a = map(int, input().split())

money = 1000
ans = 0
for i in range(0, 100000):
    m = money * i
    if m * (1000 + a) / 1000 <= n:
        ans = m
print(ans)
