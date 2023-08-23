#include<iostream>
using namespace std;

int a[200];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int j=l,k=r;j<k;j++,k--)
        {
            int t=a[j];
            a[j]=a[k];
            a[k]=t;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";

}