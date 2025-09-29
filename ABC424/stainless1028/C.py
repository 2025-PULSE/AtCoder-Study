import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
learned = [False for _ in range(n + 1)]
graph = [[] for _ in range(n + 1)]
q = deque()

for i in range(1, n + 1):
    a, b = map(int, input().split())
    if a == b == 0:
        learned[i] = True
        q.append(i)
        continue
    graph[a].append(i)
    graph[b].append(i)

while q:
    cur = q.popleft()
    for node in graph[cur]:
        if not learned[node]:
            learned[node] = True
            q.append(node)

print(len([i for i in learned[1:] if i]))
