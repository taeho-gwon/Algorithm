#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int M = 50005;
pair<int, int> a[N];
int bit[M + 4], dp[N];
int n;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i].first;
    for (int i = 1; i <= n; i++)cin >> a[i].second;
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = a[i - 1].second + 1; j <= M; j += j & -j) bit[j] = max(bit[j], dp[i - 1]);
        for (int j = a[i].second; j; j &= j - 1) dp[i] = max(dp[i], bit[j]);
        dp[i] += min(a[i].first, a[i].second);
    }
    int ans = 0;
    for (int j = a[n].second + 1; j <= M; j += j & -j) bit[j] = max(bit[j], dp[n]);
    for (int j = M; j; j &= j - 1) ans = max(ans, bit[j]);
    for (int i = 1; i <= n; i++) ans += max(a[i].first, a[i].second);
    cout << ans;
}