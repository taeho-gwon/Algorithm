#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int n;
int a[55];
int dp[55][500005][2];
int f(int num, int diff, int chk)
{
    if(num==n){
        return diff?-987654321:0;
    }
    int& ret = dp[num][diff][chk];
    if(ret!=-1) return ret;
    ret = max(f(num+1, diff, chk), f(num+1, diff+a[num], chk));
    if(diff>a[num])
    {
        ret = max(ret, f(num+1, diff-a[num], chk) + a[num]);
    }
    else
    {
        ret = max(ret, f(num+1, a[num]-diff, !chk) + diff);
    }
    return ret;
}
int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = f(0, 0, 0);
    cout<<(ans==0?-1:ans);
}