import sys
input = sys.stdin.readline

from collections import defaultdict, deque
check = defaultdict(list)

n = int(input())

skill = [0] * (n+1)
visited = [0] * (n+1)
Q = deque()

for i in range(n):
    a, b = map(int, input().split())
    skill[i+1] = [a, b]

    if a == 0 and b == 0:
        visited[i+1] = 1
        Q.append(i+1)
    else:
        if a != 0:
            check[a].append(i+1)
        if b != 0:
            check[b].append(i+1)

#print(skill)
#print(check)
while Q:
    v = Q.popleft()

    for i in check[v]:
        if visited[i] == 0:
            a, b = skill[i]
            if visited[a] or visited[b]:
                visited[i] = 1
                Q.append(i)

print(sum(visited))