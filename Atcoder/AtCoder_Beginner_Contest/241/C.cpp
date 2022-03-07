#include<iostream>
#include<vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 5; j++) {
            int hori = 0, verti = 0, dright = 0, dleft = 0;
            for (int k = 0; k < 6; k++) {
                if (mp[i][j + k] == '#') hori++;
                if (mp[j + k][i] == '#') verti++;
                if (i < n - 5) {
                    if (mp[i + k][j + k] == '#') dright++;
                    if (mp[i + k][j - k + 5] == '#') dleft++;
                }
            }
            if (hori >= 4 || verti >= 4 || dright >= 4 || dleft >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}