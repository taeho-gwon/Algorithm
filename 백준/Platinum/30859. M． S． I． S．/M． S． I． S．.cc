#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
pair<int,int> a[N];
int b[N], m[N], path[N];
int n, summax;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i].first;
    for (int i = 1; i <= n; i++)cin >> a[i].second;

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = m[i] = min(a[i].first, a[i].second);
        summax += max(a[i].first, a[i].second);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i].first > a[j].first && a[i].second > a[j].second && b[i] < b[j] + m[i]) {
                b[i] = b[j] + m[i];
                path[i] = j;
            }
        }
    }

    cout<< *max_element(b + 1, b + n + 1) + summax;
 }