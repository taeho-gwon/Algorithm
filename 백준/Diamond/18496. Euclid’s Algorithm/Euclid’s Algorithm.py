from math import gcd

def v2(a):
    ans=0
    while a%2==0:
        a//=2
        ans+=1
    return ans

d,k = map(int, input().split())
v2d, v2k = v2(d), v2(k)

d_odd = d // ( 2 ** v2d )
ans = d_odd * gcd(d_odd ** 333, k)
v2ans = v2d + v2k if v2d > 1 else [0, min(k, v2k + 2)][v2d]
print(ans * (2 ** v2ans))