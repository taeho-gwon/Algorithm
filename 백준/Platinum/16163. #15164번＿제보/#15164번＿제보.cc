#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    string s, t = "$";
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        t += s[i];
        t += "$";
    }

    int r = 0, p = 0, l = t.length();
    vector<int> a(l);
    for (int i = 0; i < l; i++) {
        if (i <= r) a[i] = min(a[2 * p - i], r - i);
        while (i - a[i] - 1 >= 0 && i + a[i] + 1 < l && t[i - a[i] - 1] == t[i + a[i] + 1]) a[i]++;
        if (r < i + a[i]) r = i + a[i], p = i;
    }
    long long ans = 0;
    for (int i = 0; i < l; i++) {
        ans += (a[i] + 1) / 2;
    }
    cout << ans;

}