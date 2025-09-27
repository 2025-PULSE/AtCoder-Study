import sys
input = sys.stdin.readline
from itertools import permutations

n = int(input())
arr = list(map(int, input().split()))

case = []
for i in range(1, n+1):
    case.append(i)

# not -1
cnt = 0
for i in arr:
    if i != -1:
        cnt += 1

for perm in permutations(case, n):
    #print(perm)
    check = 0
    for i in range(n):
        if arr[i] != -1 and arr[i] == perm[i]:
            check += 1
    
    if check == cnt:
        print("Yes")
        print(*perm)
        quit()

print("No")
