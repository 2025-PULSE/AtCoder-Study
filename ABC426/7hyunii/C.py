import sys, math
import heapq
from collections import deque, defaultdict
input = sys.stdin.readline

N, Q = map(int, input().split())
version = defaultdict(int)
for i in range(1, N+1):
    version[i] = 1

minV = 1
for _ in range(Q):
    x, y = map(int, input().split())

    cnt = 0
    for v in range(minV, x + 1):
        if version[v] > 0:
            cnt += version[v]
            version[y] += version[v]
            version[v] = 0

    while version[minV] == 0:
        minV += 1

    print(cnt)

"""
Try1 = TLE
Union Find써야 될거 같은데 코드로 아직 잘 모르겠고

Try2 = 탐색 범위 좀 줄여보자 안되면 제끼자
upgrade -> version = 0
minV => 갱신


"""