import sys, math, random
from collections import deque
input = sys.stdin.readline

#간단한 bfs 문제입니다

n = int(input())
edge = [[] for _ in range(n + 1)]
skill = [0 for _ in range(n + 1)]
qu = [tuple(map(int, input().split())) for _ in range(n)]
train = [0 for _ in range(n + 1)]
q = deque()
for i in range(1, n + 1):
    a, b = qu[i - 1]
    if a == b == 0:
        skill[i] = True
        q.append(i)
    else:
        edge[a].append(i)
        edge[b].append(i)

while q:
    x = q.popleft()
    for nxt in edge[x]:
        if skill[nxt] == False:
            skill[nxt] = True
            q.append(nxt)
    
print(sum(skill))
