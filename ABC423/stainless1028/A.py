import sys
input = lambda: sys.stdin.readline().rstrip()

x, c = map(int, input().split())
if x <= 1000:
    print(0)
    sys.exit(0)

for i in range(0, x + 1, 1000):
    if i + i // 1000 * c > x:
        print(i - 1000)
        break
