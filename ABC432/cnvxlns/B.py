from itertools import permutations

a = input()

a = [int(i) for i in a]

pool = permutations(a, len(a))

ans = 1000000000

for p in pool:
    if p[0] == 0:
        continue
    res = 0
    for i in p:
        res *= 10
        res += i
    if ans > res:
        ans = res


print(ans)
