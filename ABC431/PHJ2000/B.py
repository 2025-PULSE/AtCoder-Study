'''
로봇 초기 무게 X
부품 종류는 N개, 각 부품 i의 무게는 W_i, 처음에는 아무것도 장착 안되어 있다.
Q개 질의를 순서대로 처리, P_i가 주어지면 해당 부품을 토글
각 질의 후 현재 로봇의 무게를 출력
'''
import sys

a = list(map(int, sys.stdin.read().split()))
i = 0

X = a[i]
i += 1
N = a[i]
i += 1
W = a[i:i+N]
i += N
Q = a[i]
i += 1

att = [0] * N
cur = X
out = []

for _ in range(Q):
    p = a[i]; i += 1
    j = p - 1
    if att[j] == 0:
        att[j] = 1
        cur += W[j]
    else:
        att[j] = 0
        cur -= W[j]
    out.append(str(cur))

sys.stdout.write("\n".join(out))
