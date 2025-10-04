'''
길이가 N인 정수 수열 A
-1이거나 1~N인 정수
다음 조건을 만족하는 정수 수열 P가가 존재하는지 판단하고, 존재한다면 하나 구하라
P는 1..N수열이다.
i=1..N에 대해서 Ai!=-1이면 P=Ai가 만족한다.
아 잘못이해 했었네. P는 1..N이 각각 한 번씩만 나오는 수열이다.
A_i가 -1이 아닌 칸은 P의 값도 고정되어야 한다는 의미
-1을 뺀 값들이 중복이 있으면 불가능이고 중복이 없으면 가능이네
가능하다면 순서대로 고정시켜놓고 그대로 넣기만 하면 되겠다.
'''
n=int(input())
a=list(map(int,input().split()))
jon=[x for x in a if x!=-1]

if len(jon)!=len(set(jon)):
    print("No")
    exit()
print("Yes")
u=set(jon)
l=[x for x in range(1,n+1) if x not in u]
p=[0]*n
r=0
for i in range(n):
    if a[i]==-1:
        p[i]=l[r]
        r+=1
    else:
        p[i]=a[i]
print(*p)