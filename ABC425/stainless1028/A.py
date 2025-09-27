import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
ans = 0
for i in range(1, n + 1):
    ans += (-1) ** i * i ** 3
print(ans)
