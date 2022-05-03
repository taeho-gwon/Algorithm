#include<bits/stdc++.h>

using namespace std;
struct DATA {
	int val;
	int loc;
	bool operator<(const DATA& other) const
	{
		return val < other.val;
	}
};
DATA find_max(vector<DATA>& seg, int l, int r)
{
	DATA ret = { 0,0 };
	while (l < r)
	{
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
		l >>= 1;
		r >>= 1;
	}
	return ret;
}

void update(vector<DATA>& seg, int idx, DATA val)
{
	seg[idx] = val;
	while (idx > 1)
	{
		idx >>= 1;
		seg[idx] = max(seg[idx << 1], seg[idx << 1 | 1]);
	}
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	vector<DATA> seg(n << 1);
	vector<int> path(n);
	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		DATA mx = find_max(seg, n, n + idx);
		update(seg, n + idx, { mx.val + 1, i });
		path[i] = mx.loc;
	}
	DATA ans = find_max(seg, n, n << 1);
	cout << ans.val << "\n";

	vector<int> lis;
	int loc = ans.loc;
	for (int i = 0; i < ans.val; i++)
	{
		lis.push_back(loc);
		loc = path[loc];
	}
	for (int i = lis.size() - 1; i >= 0; i--)
	{
		cout << a[lis[i]] << " ";
	}
	return 0;
}