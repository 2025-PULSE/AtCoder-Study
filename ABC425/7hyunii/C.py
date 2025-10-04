import sys
input = sys.stdin.readline

n, Q = map(int, input().split())
arr = list(map(int, input().split()))

pfSum = [0] * (2*n + 1)
for i in range(2*n):
    pfSum[i+1] = pfSum[i] + arr[i % n]

#print(pfSum)
offset = 0
for _ in range(Q):
    q = list(map(int, input().split()))

    if q[0] == 1:
        c = q[1]
        offset = (offset + c) % n
        #print(offset)

    if q[0] == 2:
        l, r = q[1], q[2]
        start = offset + l - 1
        end = offset + r
        #print(start, end)

        ans = pfSum[end] - pfSum[start]
        #print(pfSum[end], pfSum[start])

        print(ans)

"""
4 3
3 1 4 5
2 1 3
1 1
2 2 3

3 1 4 5 / 3 1 4 5
=> 0 3 4 8 13 16 17 21 26

-> right 1
1 4 5 3 1 4 5 3
: 0 3 4 8 13 16 17 21 26

2 2 3 => 9
: 2 4 1
offset = 1
start = 1 + 2 - 1 = 2
end = 1 + 3 = 4

"""
