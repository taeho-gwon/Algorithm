#include<bits/stdc++.h>

using namespace std;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    multiset<int> ms[10001];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ms[x].insert(y);
    }


    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        for (int j = max(0, x - r); j <= min(10000, x + r); j++) {
            int rad = int(sqrt(r * r - (j - x) * (j - x)));
            ms[j].erase(ms[j].lower_bound(y - rad), ms[j].upper_bound(y + rad));
        }
    }
    int ans=0;
    for(int i=0;i<=10000;i++)
        ans += ms[i].size();
    cout<<ans;
}