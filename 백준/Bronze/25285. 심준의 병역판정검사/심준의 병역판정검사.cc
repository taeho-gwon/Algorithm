#include<cstdio>
int f(int x, int y){
if(x<141)return 6;
if(x<146)return 5;
if(x<159)return 4;
int r = y*20000/(x*x);
if(r<32||r>=70)return 4;
if(x<161)return 3;
if(r<50&&r>=40)return 1;
if((r>=37 && r<40)||(r>=50 && r<60))return 2;
return 3;
}
int main()
{
int z;
scanf("%d",&z);
while(z--)
{
int x,y;
scanf("%d%d",&x,&y);
printf("%d\n",f(x,y));
}
}