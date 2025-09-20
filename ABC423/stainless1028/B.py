import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
doors = list(map(int, input().split()))
first, second = 0, 0
for i in range(n):
    if doors[i] == 1:
        first = i
        break
for i in range(n - 1, -1, -1):
    if doors[i] == 1:
        second = i
        break
print(len(doors[first:second]))
