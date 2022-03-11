#include<iostream>
#include<vector>

#define MOD 998244353

using namespace std;
typedef long long ll;

ll modpow(ll x, ll y) {
    ll ret = 1, now = x;
    while (y) {
        if (y & 1) ret = (ret * now) % MOD;
        y >>= 1;
        now = (now * now) % MOD;
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        ll ans = 0;
        for (int i = 0; i < (s.length() + 1) / 2; i++) {
            ll cnt = s[i] - 'A';
            ans = (ans + cnt * modpow(26, (s.length() - 1) / 2 - i)) % MOD;
        }
        bool chk = true;
        for (int k = 0; k < (s.length() + 1) / 2; k++) {
            char l = s[(s.length() - 1) / 2 - k];
            char r = s[(s.length()) / 2 + k];
            if (l > r) {
                chk = false;
                break;
            } else if (l < r) {
                break;
            }
        }
        if (chk) ans = (ans + 1) % MOD;
        cout << ans << "\n";
    }
}