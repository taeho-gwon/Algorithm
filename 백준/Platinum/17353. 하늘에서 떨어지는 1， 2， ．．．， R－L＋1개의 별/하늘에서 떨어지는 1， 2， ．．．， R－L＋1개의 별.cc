#include<bits/stdc++.h>

using namespace std;

template <class TDATA, class TLAZY>
class LazySegTree
{
private:
	int n;
	int h;
	vector<TDATA> data;
	vector<TLAZY> lazy;
	TDATA id_data;
	TLAZY id_lazy;
	function<TDATA(TDATA, TDATA)> merge;
	function<TDATA(TLAZY, TDATA)> action;
	function<TLAZY(TLAZY, TLAZY)> compose;
	function<TLAZY(TLAZY, int)> f;
		 
	void down(int p)
	{
		p += n;
		for (int s = h; s > 0; s--)
		{
			int now = p >> s;
			if (lazy[now] != id_lazy)
			{
				apply(now << 1, lazy[now], 1 << (s - 1));
				apply(now << 1 | 1, lazy[now], 1 << (s - 1));
				lazy[now] = id_lazy;
			}
		}
	}

	void up(int p)
	{
		p += n;
		for (int sz = 2; p >>= 1; sz <<= 1)
		{
			data[p] = merge(data[p << 1], data[p << 1 | 1]);
			if(p<n) data[p] = action(f(lazy[p], sz), data[p]);
		}
	}

	void apply(int p, TLAZY value, int sz)
	{
		data[p] = action(f(value, sz), data[p]);
		if (p < n) lazy[p] = compose(value, lazy[p]);
	}
public:
	LazySegTree(
		int _n, TDATA _id_data, TLAZY _id_lazy,
		function<TDATA(TDATA, TDATA)> _merge,
		function<TDATA(TLAZY, TDATA)> _action,
		function<TLAZY(TLAZY, TLAZY)> _compose,
		function<TLAZY(TLAZY, int)> _f
	) : n(_n), id_data(_id_data), id_lazy(_id_lazy),
		merge(_merge), action(_action), compose(_compose), f(_f){
		data.resize(n << 1, id_data);
		lazy.resize(n, id_lazy);

		h = 0;
		while (_n)
		{
			_n >>= 1;
			h++;
		}
	}
	void initialize(vector<TDATA>& data_init)
	{
		for (int i = 0; i < n; i++) data[i + n] = data_init[i];
		for (int i = n - 1; i > 0; i--) data[i] = merge(data[i << 1], data[i << 1 | 1]);
	}

	void modify(int l, int r, TLAZY value)
	{
		if (value == id_lazy) return;
		down(l);
		down(r - 1);
		for (int ll = l + n, rr = r + n, sz = 1; ll < rr; ll >>= 1, rr >>= 1, sz <<= 1)
		{
			if (ll & 1) apply(ll++, value, sz);
			if (rr & 1) apply(--rr, value, sz);
		}
		up(l);
		up(r - 1);
	}
	TDATA query(int l, int r)
	{
		down(l);
		down(r - 1);

		TDATA ansl = id_data, ansr = id_data;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) ansl = merge(ansl, data[l++]);
			if (r & 1) ansr = merge(data[--r], ansr);
		}
		return merge(ansl, ansr);
	}
};

typedef long long ll;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, q;
	cin >> n;
	LazySegTree<ll, ll> lst(n, 0, 0, plus<ll>(), plus<ll>(), plus<ll>(), multiplies<ll>());
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i > 0; i--)a[i] -= a[i - 1];
	lst.initialize(a);

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			ll c;
			cin >> c;
			lst.modify(b - 1, c, 1);
			if (c < n) lst.modify(c, c + 1, -c + b - 1);
		}
		else cout << lst.query(0, b) << "\n";
	}
	return 0;
}