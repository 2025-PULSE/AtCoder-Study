import sys
input = sys.stdin.readline

n, r = map(int, input().split())
door = list(map(int, input().split()))
ans = 0

opened = []
for i in range(n):
    if door[i] == 0:
        opened.append(i)

if not opened:  #RTE 방지
    print(0)
    quit()

start = opened[0]
end = opened[-1] + 1
goto = 0
if start > r:
    goto = sum(door[r : start])
elif r > end:
    goto = sum(door[end : r])

ans = len(opened) + 2*(sum(door[start : end]) + goto) 

print(ans)