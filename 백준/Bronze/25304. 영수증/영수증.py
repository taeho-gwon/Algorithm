x=int(input())
n=int(input())
for i in range(n):
    p,q=map(int, input().split())
    x -= p*q
print("Yes" if x==0 else "No")