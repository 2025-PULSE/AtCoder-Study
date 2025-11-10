import sys
input = lambda: sys.stdin.buffer.readline()#.decode("ascii").rstrip()
fastprint = lambda s: sys.stdout.write(str(s) + "\n")
exit = lambda: sys.exit(0)

h, b = map(int, input().split())
if b >= h:
    fastprint(0)
else:
    fastprint(h - b)
