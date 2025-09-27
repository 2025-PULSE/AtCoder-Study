import sys
input = lambda: sys.stdin.readline().rstrip()

"""
N 범위가 작고 순열 구하기 -> 백트래킹
"""

n = int(input())
a = list(map(int, input().split()))
arr = list(range(1, n + 1))
result = [0] * n
used = [False] * (n + 1)
for i in range(n):
    if a[i] != -1:
        if used[a[i]]: # 이부분 빼먹어서 한번 틀림,,
            print("No")
            sys.exit(0)
        result[i] = a[i]
        used[a[i]] = True

def solve(k):
    if k == n:
        print("Yes")
        print(*result)
        sys.exit(0)
    if result[k] != 0:
        solve(k + 1)
    else:
        for i in range(1, n + 1):
            if used[i]:
                continue
            result[k] = i
            used[i] = True
            solve(k + 1)
            result[k] = 0
            used[i] = False

solve(0)
print("No")
