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

    int n, m, b, w;
    cin >> n >> m >> b >> w;

    ll ans = 0;
    ll cb[51][51] = {0,};
    for (int i = 1; i <= 50; i++)
        for (int j = 0; j <= i; j++) {
            if (i == 1 || j == 0 || j == i) cb[i][j] = 1;
            else cb[i][j] = (cb[i - 1][j - 1] + cb[i - 1][j]) % MOD;
        }

    vector<ll> cb_b(n * m + 1), cb_w(n * m + 1);

    for (int i = b; i <= n * m; i++) {
        if (i == b) cb_b[i] = 1;
        else {
            cb_b[i] = (cb_b[i - 1] * i) % MOD;
            cb_b[i] = (cb_b[i] * modpow(i - b, MOD - 2)) % MOD;
        }
    }

    for (int i = w; i <= n * m; i++) {
        if (i == w) cb_w[i] = 1;
        else {
            cb_w[i] = (cb_w[i - 1] * i) % MOD;
            cb_w[i] = (cb_w[i] * modpow(i - w, MOD - 2)) % MOD;
        }
    }

    ll f[51][51] = {0,}, g[51][51] = {0,};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= i; k++) {
                for (int s = 0; s <= j; s++) {
                    ll val = (cb[i][k] * cb[j][s]) % MOD;
                    if ((k + s) % 2 == 1) {
                        val *= -1;
                        val %= MOD;
                        val += MOD;
                        val %= MOD;
                    }
                    ll nowf = val * cb_w[(i - k) * (j - s)];
                    ll nowg = val * cb_b[(i - k) * (j - s)];
                    f[i][j] = (f[i][j] + nowf) % MOD;
                    g[i][j] = (g[i][j] + nowg) % MOD;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i; j++)
            for (int k = 1; k <= m; k++)
                for (int s = 1; s <= m - k; s++) {
                    ll now = (cb[n][i] * cb[n - i][j]) % MOD;
                    now = (now * cb[m][k]) % MOD;
                    now = (now * cb[m - k][s]) % MOD;
                    now = (now * f[i][k]) % MOD;
                    now = (now * g[j][s]) % MOD;
                    ans = (ans + now) % MOD;
                }
    cout << ans;
}