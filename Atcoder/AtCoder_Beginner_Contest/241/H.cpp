#include<iostream>
#include<vector>

#define MOD 998244353LL

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
    int n;
    ll m;
    vector<ll> a(n), b(n), c(n), d(n);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = (MOD - modpow(a[i], b[i] + 1)) % MOD;
    }

    for (int i = 0; i < n; i++) {
        d[i] = 1;
        ll a_inv = modpow(a[i], MOD - 2);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ll prod = (a[j] * a_inv) % MOD;
            d[i] *= MOD + 1 - prod;
            d[i] %= MOD;
        }
        d[i] = modpow(d[i], MOD - 2);
    }

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ll exp = m, ls = 1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                exp -= b[j] + 1;
                ls = (ls * c[j]) % MOD;
            }
        }
        if (exp < 0) continue;
        ll rs = 0;
        for (int j = 0; j < n; j++) {
            ll now = (d[j] * modpow(a[j], exp)) % MOD;
            rs = (rs + now) % MOD;
        }
        ans = (ans + ls * rs) % MOD;
    }
    cout << ans;

    return 0;
}