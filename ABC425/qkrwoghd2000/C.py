'''
길이 N의 정수 수열 A
Q개의 쿼리 처리
1 c A의 첫번쨰 원소를 맨 뒤로 보내는 연산 c번 반복
2 l r sigma(l,r)(Ai)를 계산한다.
N 1..10^5
Q 1..10^5
Ai 1..10^9
모든 입력 값은 정수
2번 쿼리는 한 번 이상 존재한다.
이렇게 범위가 크게 되면 쿼리를 거의 O(1)급으로 진행이 가능해야한다.
1번을 원형큐를 만듬으로써 해결하고, 부분합을 이용해서 진행한다음, 헤드 위치를 계산해서
보정을 하면 낮은 시간으로 가능해보인다.
인덱스 오류가 발생했다.

'''
n,q=map(int,input().split())
l=list(map(int,input().split()))
s=[0]*(n+1)
head=0

for i in range(n):
    s[i+1]=s[i]+l[i]

for i in range(q):
    x=list(map(int,input().split()))
    if x[0]==1:
        head=(head+x[1])%n
        pass
    else:
        l,r=x[1],x[2]
        l=(head+l-1)%n
        r=(head+r-1)%n
        if l<=r:
            print(s[r+1]-s[l])
        else:
            print((s[n]-s[l])+(s[r+1]-s[0]))
