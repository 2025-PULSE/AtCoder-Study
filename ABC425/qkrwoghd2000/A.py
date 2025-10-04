'''
단순한 공식 문제이다.
최대가 10밖에 되지 않아 그대로 해도 된다.
'''
n=int(input())
s=0
for i in range(1,n+1):
    if i%2==0:
        s+=i**3
    else:
        s-=i**3
print(s)