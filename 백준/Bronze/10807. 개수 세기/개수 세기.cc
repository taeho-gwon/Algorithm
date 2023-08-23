#include<iostream>

using namespace std;

int a[100000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int x, ans=0;
    cin>>x;
    for(int i=0;i<n;i++) if(a[i] == x) ++ans;
    cout<<ans;
}