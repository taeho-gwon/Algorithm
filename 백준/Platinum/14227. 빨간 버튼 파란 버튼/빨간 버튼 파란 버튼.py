a,b,c,d=map(int,input().split())

ans=0
while a!=c or b!=d:
    if (a==c and b!=d) or a>c or b>d:
        break
    if c%2 != d%2:
        c,d,ans = a,d-c+a, ans+c-a
        continue
    if c%2==1:
        c,d,ans=c-1,d-1,ans+1
        continue
    if a<=c//2 and b<=d//2 and 2*abs(b-a) <=abs(d-c):
        c,d,ans=c//2,d//2,ans+1
        continue
    c,d,ans = a,d-c+a,ans+c-a
else:
    print(ans)
    exit()
print(-1)