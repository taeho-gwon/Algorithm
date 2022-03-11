#include<iostream>
#include<vector>

#define MOD 998244353

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> dp[11];
    cin >> n;
    for (int i = 0; i < 11; i++) {
        dp[i].resize(n + 1);
        if (i >= 1 && i < 10) dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 10; j++) {
            dp[j][i] = ((dp[j - 1][i - 1] + dp[j][i - 1]) % MOD + dp[j + 1][i - 1]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    cout << ans;
}