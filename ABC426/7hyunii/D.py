import sys, math
import heapq
from collections import deque, defaultdict
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    s = input().strip()
    
    if len(set(s)) == 1:
        print(0)
        continue
    
    cnt0 = s.count('0')
    cnt1 = s.count('1')
    
    length = 0
    Max0 = 0
    for i in s:
        if i == "0":
            length += 1
            Max0 = max(length, Max0)
        else:
            length = 0

    length = 0
    Max1 = 0
    for i in s:
        if i == "1":
            length += 1
            Max1 = max(length, Max1)
        else:
            length = 0

    Zero = 2*(cnt0 - Max0) + cnt1
    One = 2*(cnt1 - Max1) + cnt0
    print(min(Zero, One))

    
"""
0 1 => two dummy
    => ans += minimum

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