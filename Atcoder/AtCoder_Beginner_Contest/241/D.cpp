#include<iostream>
#include<set>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    multiset<long long> ms;

    while (q--) {
        int t, k;
        long long x;
        cin >> t >> x;
        if (t != 1) cin >> k;
        if (t == 1) {
            ms.insert(x);
        } else if (t == 2) {
            auto it = ms.upper_bound(x);
            while (it != ms.begin() && k--)
                --it;
            if (k > 0) cout << -1 << " ";
            else cout << *it << " ";
        } else {
            auto it = ms.lower_bound(x);
            while (it != ms.end() && --k)
                ++it;
            if (it == ms.end()) cout << -1 << " ";
            else cout << *it << " ";
        }
    }

    return 0;
}