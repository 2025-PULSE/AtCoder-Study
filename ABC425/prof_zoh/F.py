import sys
input = sys.stdin.readline

mod = 998244353
n = int(input())
st = input().rstrip("\n")
dp = [0] * (1 << n)
dp[(1 << n) - 1] = 1
for i in range((1 << n) - 1, -1, -1):
    dp[i] %= mod
    p = "0"
    for j in range(n):
        if (i & (1 << j)):
            if st[j] != p:
                dp[i ^ (1 << j)] += dp[i]
            p = st[j]
print(dp[0] % mod)
    
