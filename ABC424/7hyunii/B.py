import sys
input = sys.stdin.readline

from collections import defaultdict
solved = defaultdict(list)

n, m, k = map(int, input().split())
for _ in range(k):
    a, b = map(int, input().split())
    
    solved[a].append(b)

    if len(solved[a]) == m:
        print(a, end=" ")