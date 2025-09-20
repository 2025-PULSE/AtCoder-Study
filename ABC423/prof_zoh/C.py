import sys, math
input = sys.stdin.readline

n, r = map(int, input().split())
door = list(map(int, input().split()))
left = right = -1

for i in range(r):
    if door[i] == 0:
        left = i + 1
        break

for i in range(n - 1, r - 1, -1):
    if door[i] == 0:
        right = i
        break

unlock_l = unlock_r = lock = 0
if left != -1:
    unlock_l = sum(door[left:r]) 
if right != -1:
    unlock_r = sum(door[r:right])

if left == -1 and right == -1:
    unlock_l = unlock_r = lock = 0
elif left == -1:
    lock = right - r + 1
elif right == -1:
    lock = r - left + 1
else:
    lock = right - left + 2
print(unlock_l + unlock_r + lock)
