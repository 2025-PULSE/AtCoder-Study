import sys, math
input = sys.stdin.readline

n = int(input())
door = list(map(int, input().split()))
reached = [1 for _ in range(n + 1)]
reached[0] = reached[n] = 0
for i in range(n):
    if door[i]:
        break
    reached[i + 1] = 0

for i in range(n - 1, -1, -1):
    if door[i]:
        break
    reached[i] = 0

print(sum(reached))
