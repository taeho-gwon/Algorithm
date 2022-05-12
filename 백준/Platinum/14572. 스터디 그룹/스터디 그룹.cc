#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, k, d;
    cin >> n >> k >> d;

    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int m, dd, algo=0;
        cin >> m >> dd;
        while (m--) {
            int x;
            cin >> x;
            algo |= 1 << x;
        }
        s.push_back({dd, algo});
    }
    sort(s.begin(), s.end());
    int al[31] = {0,}, ans = 0;
    for (int i = 0, j = 0; j < n;) {
        while (s[j].first - s[i].first > d) {
            for (int t = 1; t <= k; t++) {
                if (s[i].second & 1 << t) al[t]--;
            }
            i++;
        }
        for (int t = 1; t <= k; t++) {
            if (s[j].second & 1 << t) al[t]++;
        }
        j++;
        int B = 0, b = 0;
        for (int t = 1; t <= k; t++) {
            if (al[t] > 0) B++;
            if (al[t] == j - i) b++;
        }

        ans = max(ans, (B - b) * (j - i));
    }
    cout << ans;
}