import sys
input = lambda: sys.stdin.readline().rstrip()

v = {"Ocelot": 1, "Serval": 2, "Lynx": 3}
x, y = input().split()
print("Yes" if v[x] >= v[y] else "No")
