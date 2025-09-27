import sys, math, random
import heapq
from collections import deque
input = sys.stdin.readline

n = int(input())
s = 0
for i in range(1, n + 1):
    s += pow(-1, i) * pow(i, 3)
print(s)
