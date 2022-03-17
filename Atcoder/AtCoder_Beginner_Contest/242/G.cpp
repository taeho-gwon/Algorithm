#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>


int n, q, sqrtN;

struct Query {
    int idx, l, r;

    bool operator<(Query &other) const {
        if (l / sqrtN == other.l / sqrtN) return r < other.r;
        return l / sqrtN < other.l / sqrtN;
    }
};

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    sqrtN = (int) sqrt(n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;

    vector<Query> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].r++;
        query[i].idx = i;
    }
    sort(query.begin(), query.end());

    int l = query[0].l, r = query[0].r;
    vector<int> cnt(n + 1);
    int now = 0;
    vector<int> ans(q);
    for (int i = l; i < r; i++) {
        now += cnt[a[i]]++ % 2;
    }

    ans[query[0].idx] = now;
    for (int i = 1; i < q; i++) {
        while (l < query[i].l) now -= --cnt[a[l++]] % 2;
        while (l > query[i].l) now += cnt[a[--l]]++ % 2;
        while (r < query[i].r) now += cnt[a[++r]]++ % 2;
        while (r > query[i].r) now -= --cnt[a[r--]] % 2;
        ans[query[i].idx] = now;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}