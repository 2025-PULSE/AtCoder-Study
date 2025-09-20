'''
1..N 스킬
Ai, Bi 주어짐
0, 0이라면 스킬 i를 배운 것이다.
아니라면 Ai나 Bi중에 하나를 배운경우에 한하여 스킬 i를 배울 수 있다.
예를 들어서 i2가 1,3이라면 i1또는 i3을 배웠을 때 배울 수 있다.
이미 배운 스킬을 포함해서 최종적으로 배울 수 있는 스킬의 갯수를 구하라
그래프 전파 문제이고, OR조건이니 BFS를 활용해서 해보자.
일단 잘된거 같다.
AC
'''
from collections import deque
n=int(input())
a=[0]*(n+1)
b=[0]*(n+1)
q=deque()
v=[False]*(n+1)
s=[]
adj=[[] for _ in range(n+1)]

for i in range(1,n+1):
    x,y=map(int,input().split())
    a[i],b[i]=x,y
    if x==0 and y==0:
        s.append(i)

for i in range(1,n+1):
    adj[a[i]].append(i)
    adj[b[i]].append(i)
    
q.extend(s)
for i in s:
    v[i]=True

while q:
    z=q.popleft()
    for c in adj[z]:
        if not v[c]:
            v[c]=True
            q.append(c)

print(sum(v))