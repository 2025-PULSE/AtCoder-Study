import sys
input = sys.stdin.readline

n = int(input())
door = list(map(int, input().split()))
ans = [0] * (n+1)

for i in range(n):
    if door[i]:
        break
    else:
        ans[i+1] = 1
    
for i in range(n-1, -1, -1):
    if door[i]:
        break
    else:
        ans[i] = 1

ans[0] = ans[-1] = 1
print(ans.count(0))