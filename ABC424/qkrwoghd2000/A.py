'''
이등변삼각형인지를 판별하는 문제이다.
서로 길이가 같은 변이 2개이상면 이등변삼각형이다.
AC
'''
a,b,c=map(int,input().split())

if(a==b) or (b==c) or (a==c):
    print("Yes")
else:
    print("No")