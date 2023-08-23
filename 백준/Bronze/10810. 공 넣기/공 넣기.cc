#include<iostream>

using namespace std;

int a[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        for(int j=l;j<=r;j++) a[j]=x;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}