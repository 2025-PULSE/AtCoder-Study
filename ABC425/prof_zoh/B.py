import sys, math, random
import heapq
from collections import deque
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
flag = True
num = []
for i in range(1, n + 1):
    if arr.count(i) > 1:
        flag = False
        break
    elif arr.count(i) == 0:
        num.append(i)

if flag:
    print("Yes")
    for i in range(n):
        if arr[i] == -1:
            arr[i] = num.pop()
    print(*arr)
else:
    print("No")
