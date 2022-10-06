#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio();

    int n;
    string s;
    cin >> n >> s;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long l = 0, r = 0;
        for (int j = i - 1; j >= 0 && s[j] != s[i]; j--) l++;
        for (int j = i + 1; j < n && s[j] != s[i]; j++) r++;

        ans += l * r;
        if (l) ans += l - 1;
        if (r) ans += r - 1;
    }
    cout << ans;
}