import sys
input = lambda: sys.stdin.readline().rstrip()

s = list(input())
c = list(set(s))
print(c[0] if s.count(c[0]) == 1 else c[1])
