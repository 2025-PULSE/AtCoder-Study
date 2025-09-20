import sys, heapq
input = sys.stdin.readline

heap = []
n, k = map(int, input().split())
inn = 0
out = n
q = [tuple(map(int, input().split())) for _ in range(n)]
number = 0
tl = 0
while inn < n:
    if not heap:
        a, b, c = q[inn]
        tl = a = max(a, tl)
        print(a)
        number += c
        heapq.heappush(heap, (a + b, c))
        inn += 1
    else:
        if q[inn][0] < heap[0][0]:
            t = q[inn][0]
            while q[inn][2] + number > k:
                t, X = heapq.heappop(heap)
                t = max(t, tl)
                number -= X
            number += q[inn][2]
            tl = t = max(tl, t)
            print(t)
            heapq.heappush(heap, (t + q[inn][1], q[inn][2]))
            inn += 1
        else:
            t, X = heapq.heappop(heap)
            tl = t = max(tl, t)
            number -= X
