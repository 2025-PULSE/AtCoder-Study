import sys
input = lambda: sys.stdin.buffer.readline()#.decode("ascii").rstrip()
fprint = lambda s: sys.stdout.write(str(s) + "\n")
exit = lambda: sys.exit(0)

n, x, y = map(int, input().split())
arr = list(map(int, input().split()))
d = y - x
r = (arr[0] * x) % d
a_min, a_max = float("inf"), 0

for a in arr:
    if (a * x) % d != r:
        print(-1)
        exit()
    a_min = min(a_min, a)
    a_max = max(a_max, a)

w_min = a_max * x
w_max = a_min * y
if w_min > w_max:
    print(-1)
    exit()

w = w_max - (w_max % d - r + d) % d
if w < w_min:
    print(-1)
    exit()

result = 0
for a in arr:
    result += (w - a * x) // d
print(result)

"""
s + l = a
sx + ly = w
(a - l)x + ly = w
ax - lx + ly = w
l(y - x) = w - ax
l = (w - ax) / (y - x)
(w - ax) % (y - x) == 0
w % (y - x) == ax % (y - x)
max(arr) * x <= w <= min(arr) * y
sum(l) = (n * w - x * sum(arr)) / (y - x)
"""
