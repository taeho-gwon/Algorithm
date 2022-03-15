#include<iostream>

using namespace std;

typedef __int128 ll;

ll gcd(ll x, ll y) {
    if (y == 0)return x;
    return gcd(y, x % y);
}

ll egcd(ll a, ll b, ll s, ll &x, ll &y) {
    if (b == 0) {
        x = s / a;
        y = 0;
        return a;
    }
    ll d = egcd(b, a % b, s, y, x);
    y = ((y - a / b * x) % (a / d) + (a / d)) % (a / d);
    x = (s - b * y) / a;

    return d;

}

bool solve(long long a_, long long b_, long long s_) {
    ll a = a_, b = b_, s = s_;
    if (a == 0 && b == 0)
        return s == 0;
    if (a == 0) return s % b == 0;
    if (b == 0)return s % a == 0;
    ll x, y, g = egcd(a, b, s, x, y);
    if (s % g != 0) return false;
    for (ll i = -g * x / b; i <= g * y / a; i++) {
        if (gcd(x + i * b / g, y - i * a / g) == 1)
            return true;
    }
    return false;

}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, s;
    cin >> a >> b >> s;
    cout << (solve(a, b, s) ? "YES" : "NO");
}