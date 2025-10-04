import sys, math
import heapq
from collections import deque, defaultdict
input = sys.stdin.readline

s = input().strip()

for i in s:
    if s.count(i) == 1:
        print(i)
        break
