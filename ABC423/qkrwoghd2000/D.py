'''
한번에 k명 수용 가능한 식당이 있다.
한줄로 서는 대기줄이 있다(큐)
N명의 손님 그룹이 차례로 찾아온다.
도착 순서 기준으로 1~N
그룹 i는 C명으로 이루어져 있으며 A시간에 줄을 서고, 식당에서 B시간이 지나면 떠난다.
각 그룹은 2가지 조건을 동시에 만족해야 진입이 가능하다.
줄 맨앞에 있어야 한다.
들어가고 싶은 사람 + 식당안에 있는 인원이 K이하여야 한다.
모든 그룹에 대해 식당에 들어가는 시간을 구하여라
일단 큐로 동작하는 시뮬레이션에 가깝다.
시간을 기준으로 큐형태로 진행을 하고, 지정된 시간이 되면 나가게 하고, 바로 입장이 불가하면 다음 시간대로 점프하니 타이머가 따로 필요없다.
대기줄은 큐로, 퇴장은 최소힙으로 처리하자., 힙 구성 요서는 [퇴장시각과 인원]
tle
'''
import heapq
from collections import deque
n,k=map(int,input().split())
a=[0]*n
b=[0]*n
c=[0]*n
for i in range(n):
    a[i],b[i],c[i]=map(int,input().split())

cc=0
q=deque()
hp=[]
ans=[-1]*n
i=0
t=0

while i<n or q or hp:
    while hp and hp[0][0]<=t:
        eh, ep=heapq.heappop(hp)
        cc-=ep
    
    while i<n and a[i]==t:
        q.append(i)
        i+=1
