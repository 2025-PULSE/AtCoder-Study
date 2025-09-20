import sys, math, random
input = sys.stdin.readline

n, m, k = map(int, input().split())

q = [tuple(map(int, input().split())) for _ in range(k)]

# 빠르게 짜려고 의식의 흐름대로 구현하느라 알고리즘 성능은 일부로 안좋게 짰습니다.
pu = []
for i in range(1, n + 1):
    flag = True
    for j in range(1, m + 1):
        if (i, j) in q:
            continue
        flag = False
    if flag == False:
        continue
    for j in range(k - 1, -1, -1):
        pe, pr = q[j]
        if pe == i:
            pu.append((j, pe))
            break
pu.sort()
for x, y in pu:
    print(y, end = " ")
