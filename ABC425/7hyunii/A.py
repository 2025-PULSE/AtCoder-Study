import sys
input = sys.stdin.readline

n = int(input())
ans = 0
for i in range(1, n+1):
    if i % 2:
        ans += -(i**2 * i)
    else:
        ans += (i**2 * i)
        
print(ans)
