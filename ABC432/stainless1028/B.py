import sys
input = lambda: sys.stdin.buffer.readline().decode("ascii").rstrip()
fprint = lambda s: sys.stdout.write(str(s) + "\n")
exit = lambda: sys.exit(0)

x = list(input())
digits = sorted(x)

if digits[0] == "0":
    for i in range(1, len(digits)):
        if digits[i] != "0":
            digits[0], digits[i] = digits[i], digits[0]
            break
print("".join(digits))
