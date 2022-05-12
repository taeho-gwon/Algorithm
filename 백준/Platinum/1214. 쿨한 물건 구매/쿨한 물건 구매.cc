#include<iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    long long d, p, q;
    cin >> d >> p >> q;
    if (p < q) p ^= q ^= p ^= q;
    long long ans = d + p;
    for (int i = 0; i <= min(d / p + 1, q - 1); i++) {
        int pay_q = (d - i * p + q - 1) / q;
        ans = min(ans, q * pay_q + p * i);
    }
    cout << ans;
}