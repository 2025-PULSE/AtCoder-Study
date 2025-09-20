'''
N명이 M문제로 이루어진 프로그래밍 대회 참가
사람 1..N, 문제 1..M
K개의 이벤트가 발생
1<=i<=K
이벤트는 같은 이벤트 나오지 않고, 이벤트를 통해서만 풀 수 있다.
모든 문제를 푼 사람들의 번호를 출력
여러명이라면 모든 문제를 해결을 완료한 시각으로 한다.
동일 이벤트가 안나오니, 카운트 해서 해결하자.
AC
'''
n,m,k=map(int,input().split())
ans=[0]*(n+1)
for _ in range(k):
    a,b=map(int,input().split())
    ans[a]+=1
    if ans[a]==m:
        print(a,end=" ")