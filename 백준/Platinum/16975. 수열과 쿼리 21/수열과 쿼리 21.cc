#include<vector>
#include<functional>
#include<iostream>

using namespace std;

template<class TDATA, class TLAZY>
class LazySegTree {
private:
    int n, h;
    vector<TDATA> data;
    vector<TLAZY> lazy;
    TDATA id_data;
    TLAZY id_lazy;
    function<TDATA(TDATA, TDATA)> merge;
    function<TDATA(TLAZY, TDATA)> action;
    function<TLAZY(TLAZY, TLAZY)> compose;

    void down(int p) {
        for (int s = h; s > 0; s--) {
            int now = p >> s;
            if (lazy[now] != id_lazy) {
                apply(now << 1, lazy[now]);
                apply(now << 1 | 1, lazy[now]);
                lazy[now] = id_lazy;
            }
        }
    }

    void up(int p) {
        while (p >>= 1) {
            data[p] = merge(data[p << 1], data[p << 1 | 1]);
            if (p < n) data[p] = action(lazy[p], data[p]);
        }
    }

    void apply(int p, TLAZY value) {
        data[p] = action(value, data[p]);
        if (p < n) lazy[p] = compose(value, lazy[p]);
    }

public:
    LazySegTree(
            int _n, TDATA _id_data, TLAZY _id_lazy,
            function<TDATA(TDATA, TDATA)> _merge,
            function<TDATA(TLAZY, TDATA)> _action,
            function<TLAZY(TLAZY, TLAZY)> _compose
    ) : n(_n), id_data(_id_data), id_lazy(_id_lazy),
        merge(_merge), action(_action), compose(_compose) {
        data.resize(n << 1, id_data);
        lazy.resize(n, id_lazy);
        for (h = 1; _n >>= 1; h++);
    }

    void initialize(vector<TDATA> &data_init) {
        for (int i = 0; i < n; i++) data[i + n] = data_init[i];
        for (int i = n - 1; i > 0; i--) data[i] = merge(data[i << 1], data[i << 1 | 1]);
    }

    void modify(int l, int r, TLAZY value) {
        if (value == id_lazy) return;
        l += n, r += n;
        down(l);
        down(r - 1);
        for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
            if (ll & 1) apply(ll++, value);
            if (rr & 1) apply(--rr, value);
        }
        up(l);
        up(r - 1);
    }

    TDATA query(int l, int r) {
        l += n, r += n;
        down(l);
        down(r - 1);

        TDATA ansl, ansr;
        for (ansl = ansr = id_data; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = merge(ansl, data[l++]);
            if (r & 1) ansr = merge(data[--r], ansr);
        }
        return merge(ansl, ansr);
    }
};

typedef long long ll;
struct DATA {
    ll val;
    int sz;
};

DATA f_merge(DATA x, DATA y) {
    return {x.val + y.val, x.sz + y.sz};
}

DATA f_apply(ll x, DATA y) {
    return {y.val + x * y.sz, y.sz};
}

ll f_compose(ll x, ll y) {
    return x + y;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vector<DATA> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].sz = 1;
    }

    LazySegTree<DATA, ll> lst(n, DATA{0, 0}, 0, f_merge, f_apply, f_compose);
    lst.initialize(a);
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            lst.modify(l - 1, r, k);
        } else {
            int x;
            cin >> x;
            cout << lst.query(x - 1, x).val << "\n";
        }
    }
}