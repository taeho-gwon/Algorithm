#include<iostream>

using namespace std;

string s;
int dp[1004][1004];
const int MOD = 10007;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> s;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; i + j <= s.length(); j++) {
            if (i == 1) dp[j][i + j] = 1;
            else {
                dp[j][i + j] = dp[j + 1][i + j] + dp[j][i + j - 1] + (s[j] == s[i + j - 1] ? 1 : -dp[j + 1][i + j - 1]);
                dp[j][i + j] = (dp[j][i + j] + MOD) % MOD;
            }
        }
    }
    cout << dp[0][s.length()];
}