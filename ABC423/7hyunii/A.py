import sys
input = sys.stdin.readline

x, c = map(int, input().split())
cost = 1000 + c

if cost > x:
    dummy = 0
else:
    dummy = x // cost

ans = 1000 * dummy

print(ans)
