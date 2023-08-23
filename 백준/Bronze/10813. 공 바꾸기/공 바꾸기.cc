#include<iostream>

using namespace std;

int a[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=i;
    
    for(int i=0;i<m;i++)
    {
        int l,r,t;
        cin>>l>>r;
        t=a[l];
        a[l]=a[r];
        a[r]=t;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}