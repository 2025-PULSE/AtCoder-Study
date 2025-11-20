import sys
input = lambda: sys.stdin.buffer.readline()#.decode("ascii").rstrip()
fprint = lambda s: sys.stdout.write(str(s) + "\n")
exit = lambda: sys.exit(0)

a = list(map(int, input().split()))
a.sort(reverse=True)
print("".join(map(str, a)))
