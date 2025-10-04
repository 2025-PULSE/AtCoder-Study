import sys, math
import heapq
from collections import deque, defaultdict
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    s = input().strip()

    blocks = 1
    for i in range(1, n):
        if s[i] != s[i-1]:
            blocks += 1
    
    if s[0] == s[-1]:
        print((blocks - 1) * 2)
    else:
        print(blocks)
 
"""
01001
0 1 00 1

11 00 1
1 000 1
1 0000
00000


110010111100101
11 00 1 0 1111 00 1 0 1

1 00 1 0 1111 000 1 0 1
00 1 0 1111 0000  1 0 1
0 1 0 11111 0000  1 0 1
1 0 111111  0000  1 0 1
0 111111  00000   1 0 1
1111111   00000   1 0 1
1111111   000000    1 0
11111111   000000     1
11111111   0000000
0 -> 1 => 16번
"""