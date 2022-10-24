#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

bool is_prime(ll a) {
    if (a == 1) return false;
    if (a == 2 || a == 3 || a == 5) return true;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (is_prime(n)) {
        cout << "-1";
        return 0;
    }

    ll m = n;
    vector<ll> primes;

    for (ll i = 2; i * i <= m; i += 2) {
        while (m % i == 0) {
            m /= i;
            primes.push_back(i);
        }
        if (i == 2) i--;
    }
    if (m != 1) primes.push_back(m);

    for (int i = 0; i < primes.size(); i += 2) {
        ll now = primes[i] * primes[i + 1];
        if (i == primes.size() - 3) {
            now *= primes[i + 2];
            i++;
        }
        cout << now << "\n";
    }
}