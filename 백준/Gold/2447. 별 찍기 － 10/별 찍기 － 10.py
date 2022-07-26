n,s=int(input()),'*'
while n>1:k=[c*3 for c in s];s=k+[c+' '*len(c)+c for c in s]+k;n//=3
print(' '.join(s))