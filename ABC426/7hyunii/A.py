import sys, math
import heapq
from collections import deque, defaultdict
input = sys.stdin.readline

x, y = input().split()
arr = ["Ocelot", "Serval", "Lynx"]

if arr.index(x) >= arr.index(y):
    print("Yes")
else:
    print("No")