#include <bits/stdc++.h>
using namespace std;

vector<int> dv;
int dp[10004][104];

int f(int r, int c)
{
    if(r<c) r^=c^=r^=c;
    int& ret = dp[r][c];
    if(ret==0) {
        if(r%c==0) ret = r/c;
        else if(r>1000) ret = f(r-c, c) + 1;
        else {
            ret = r * c;
            for (int i = 1; i < r; i++) {
                ret = min(ret, f(i, c) + f(r - i, c));
            }

            for (int i = 1; i < c; i++) {
                ret = min(ret, f(r, i) + f(r, c-i));
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    cout<<f(n,m);
}