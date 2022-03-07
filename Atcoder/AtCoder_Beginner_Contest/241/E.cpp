#include<iostream>
#include<vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n), visit(n);

    long long x = 0, t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (visit[x % n] == 0 && t < k) {
        visit[x % n] = ++t;
        x += a[x % n];
    }

    if (t == k) {
        cout << x;
        return 0;
    }

    long long cycle_sum = 0;
    for (int i = 0; i < n; i++) {
        if (visit[i] >= visit[x % n] && visit[i] <= t) cycle_sum += a[i];
    }
    int cycle_len = t + 1 - visit[x % n];
    x += (k - t) / cycle_len * cycle_sum;
    t += (k - t) / cycle_len * cycle_len;
    while (t++ < k)
        x += a[x % n];
    cout << x;
    return 0;
}