#include<iostream>
#include<vector>

#define MOD 998244353

using namespace std;
typedef long long ll;

char trans(char c, int t) {
    return (char) (((c - 'A') + t) % 3 + 'A');
}

char f(ll t, ll k, string &s) {
    if (t == 0) return s[k];
    return trans(f(t - 1, k >> 1, s), k % 2 + 1);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        ll t, k;
        cin >> t >> k;
        if (t > 60) t = t % 3 + 60;
        cout << f(t, k - 1, s) << "\n";
    }
}