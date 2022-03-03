#include<iostream>
#include<map>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, x;
    cin >> n >> m;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (a.find(x) == a.end())
            a[x] = 0;
        a[x]++;
    }
    for (int j = 0; j < m; j++) {
        cin >> x;
        if (b.find(x) == b.end())
            b[x] = 0;
        b[x]++;
    }

    for (auto[x, y]: b) {
        if (a.find(x) == a.end() || a[x] < y) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}