#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#define MOD (1LL<<32)
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;

class Segtree
{
/* 데이터 타입과 lazy의 identity 수정*/
/*--------------------------------------------*/
private:
	typedef ll TDATA;
	typedef pll TLAZY;
	const TLAZY ID = pll(1LL, 0LL);
/*--------------------------------------------*/
	vector<TDATA> v;
	vector<TLAZY> lazy;
	int sz;

public:
	Segtree(int n=0)
	{
		resize(n);
	}
	Segtree(vector<TDATA>& data)
	{
		resize(data.size());
		init(data, 1, 0, sz);
	}
private:

	void resize(int n)
	{
		sz = n;
		v.resize(sz * 4);
		lazy.resize(sz * 4, ID);
	}
	TDATA init(vector<TDATA>& data, int node, int s, int e)
	{
		if (s + 1 == e) return v[node] = data[s];
		int mid = (s + e) / 2;
		return v[node] = merge(init(data, node * 2, s, mid), init(data, node * 2 + 1, mid, e));
	}
	TDATA query(int node, int s, int e, int l, int r)
	{
		propagate(node, s, e);
		if (r <= s || e <= l) return 0;
		if (l <= s && e <= r) return v[node];
		int mid = (s + e) / 2;
		return merge(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid, e, l, r));
	}
	void propagate(int node, int s, int e)
	{
		if (lazy[node] == ID) return;
		if (s + 1 != e)
		{
			compose(lazy[node], lazy[node * 2]);
			compose(lazy[node], lazy[node * 2 + 1]);
		}
		calc(node, e - s);
	}

	void update(int node, int s, int e, int l, int r, TLAZY act)
	{
		propagate(node, s, e);
		if (r <= s || e <= l)return;
		if (l <= s && e <= r)
		{
			compose(act, lazy[node]);
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		update(node * 2, s, mid, l, r, act);
		update(node * 2 + 1, mid, e, l, r, act);
		v[node] = merge(v[node * 2], v[node * 2 + 1]);
	}


	TDATA query(int l, int r)
	{
		return query(1, 0, sz, l, r);
	}
	void update(int l, int r, TLAZY act)
	{
		update(1, 0, sz, l, r, act);
	}


	/* 여기부터 작성 */

	/* calc
		node번째의 segment tree 노드에 lazy를 계산한후 lazy를 초기화
		input
			node : lazy를 계산할 노드 번호
			cnt : 세그먼트의 크기
	*/
	void calc(int node, int cnt)
	{
		v[node] *= lazy[node].first;
		v[node] %= MOD;
		v[node] += lazy[node].second * cnt;
		v[node] %= MOD;
		lazy[node] = ID;
	}

	/* compose
		lazy 2개를 합성, y를 x o y로 바꿈
		input
			x, y : 위에서 주어짐
	*/
	void compose(TLAZY x, TLAZY& y)
	{
		y.first *= x.first;
		y.first %= MOD;
		y.second *= x.first;
		y.second %= MOD;
		y.second += x.second;
		y.second %= MOD;
	}

	/* merge
		세그먼트 트리의 노드 2개를 병합
		input
			l,r : 병합할 노드들
	*/
	TDATA merge(TDATA l, TDATA r)
	{
		return (l + r) % MOD;
	}
public:
	// 원하는 쿼리들을 작성
	TDATA range_sum(int l, int r)
	{
		return query(l, r);
	}

	void range_update_prod(int l, int r, ll prod)
	{
		update(l, r, pll(prod, 0));
	}
	void range_update_add(int l, int r, ll add)
	{
		update(l, r, pll(1LL, add));
	}
};

class HeavyLightDecomposition
{
private:
	vector< vector<int>> adj;
	vector<int> depth, par, weight, num, hedge, top, esc;
	Segtree* seg;
	int n;
	void dfs(int now, int prev)
	{
		par[now] = prev;
		weight[now] = 1;
		for (auto& x : adj[now])
		{
			if (x == prev)continue;
			depth[x] = depth[now] + 1;
			dfs(x, now);
			weight[now] += weight[x];
			if (hedge[now] == 0 || weight[x] > weight[hedge[now]])
				hedge[now] = x;
		}
	}
	int c = 0;
	void dfs2(int now,int prev)
	{
		num[now] = c++;
		if (hedge[now])
		{
			top[hedge[now]] = top[now];
			dfs2(hedge[now], now);
			for (auto& x : adj[now])
			{
				if (x == prev || x == hedge[now])continue;
				top[x] = x;
				dfs2(x, now);
			}
		}
		esc[now] = c;
	}
public:
	HeavyLightDecomposition(int _n) :n{ _n }
	{
		adj.resize(n + 1);
		depth.resize(n + 1);
		par.resize(n + 1);
		weight.resize(n + 1);
		num.resize(n + 1);
		hedge.resize(n + 1);
		top.resize(n + 1);
		esc.resize(n + 1);
		seg = new Segtree(n);
	}
	void add_edge(int x, int y)
	{
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void construct(int root)
	{
		dfs(root, root);
		top[root] = root;
		dfs2(root, root);
	}

	void q1(int x, ll v)
	{
		seg->range_update_add(num[x], esc[x], v);
	}
	void q2(int x, int y, ll v)
	{
		while (top[x] != top[y])
		{
			if (depth[top[x]] < depth[top[y]]) swap(x, y);
			seg->range_update_add(num[top[x]], num[x]+1, v);
			x = par[top[x]];
		}
		if (depth[x] > depth[y]) swap(x, y);
		seg->range_update_add(num[x], num[y]+1, v);
	}
	void q3(int x, ll v)
	{
		seg->range_update_prod(num[x], esc[x], v);
	}
	void q4(int x, int y, ll v)
	{
		while (top[x] != top[y])
		{
			if (depth[top[x]] < depth[top[y]]) swap(x, y);
			seg->range_update_prod(num[top[x]], num[x] + 1, v);
			x = par[top[x]];
		}
		if (depth[x] > depth[y]) swap(x, y);
		seg->range_update_prod(num[x], num[y] + 1, v);
	}
	ll q5(int x)
	{
		return seg->range_sum(num[x], esc[x]);
	}
	ll q6(int x, int y)
	{
		ll ret = 0;
		while (top[x] != top[y])
		{
			if (depth[top[x]] < depth[top[y]]) swap(x, y);
			ret += seg->range_sum(num[top[x]], num[x] + 1);
			ret %= MOD;
			x = par[top[x]];
		}
		if (depth[x] > depth[y]) swap(x, y);

		ret += seg->range_sum(num[x], num[y] + 1);
		ret %= MOD;
		return ret;
	}
};
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	HeavyLightDecomposition hld = HeavyLightDecomposition(n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		hld.add_edge(x, y);
	}
	hld.construct(1);
	while (q--)
	{
		int x, y;
		ll v;
		cin >> x;
		if (x == 1)
		{
			cin >> x >> v;
			hld.q1(x, v);
		}
		else if (x == 2)
		{
			cin >> x >> y >> v;
			hld.q2(x, y, v);
		}
		else if (x == 3)
		{
			cin >> x >> v;
			hld.q3(x, v);
		}
		else if (x == 4)
		{
			cin >> x >> y >> v;
			hld.q4(x, y, v);
		}
		else if (x == 5)
		{
			cin >> x;
			cout << hld.q5(x) << "\n";
		}
		else
		{
			cin >> x >> y;
			cout << hld.q6(x, y) << "\n";
		}
	}
}