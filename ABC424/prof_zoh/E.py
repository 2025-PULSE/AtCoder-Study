import sys, math, random
import heapq
from collections import deque
input = sys.stdin.readline

'''
D를 풀다 폭사한 흔적...
def solve():
    H, W = map(int, input().split())
    S = [[0 for _ in range(W + 1)]] + [[0] + list(input().rstrip("\n")) for _ in range(H)]
    ans = 0
    for k in range(4, 0, -1):
        for i in range(2, H):
            for j in range(2, W):
                if S[i][j] == '.':
                    continue
                cnt = 0
                four = [(i - 1, j - 1), (i, j - 1), (i - 1, j), (i, j)]
                for x, y in four:
                    flag = True
                    for dx in range(2):
                        for dy in range(2):
                            nx = x + dx
                            ny = y + dy
                            if S[nx][ny] == '.':
                                flag = False
                                break
                    if flag:
                        cnt += 1
                if cnt == k:
                    ans += 1
                    S[i][j] = '.'
    return ans    
'''            

# 2^31 > 10^9, 즉 최대 3.2 * 1e6번 돌아갈 거라는 믿음으로 제출.

for _ in range(int(input())):
    N, K, X = map(int, input().split())
    A = list(map(int, input().split()))
    heap = []
    for i in range(N):
        heapq.heappush(heap, (-A[i], 1))
    sz = ct = 0
    while K > 0:
        sz, ct = heapq.heappop(heap)
        if K - ct < 0:
            heapq.heappush(heap, (sz / 2, K * 2))
            heapq.heappush(heap, (sz, ct - K))
            break
        K -= ct
        heapq.heappush(heap, (sz / 2, ct * 2))
    v = 0
    while X > 0:
        v, ct = heapq.heappop(heap)
        X -= ct
    print(-v)
