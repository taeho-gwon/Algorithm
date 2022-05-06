#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
ll k;
vector<ll> a, ps;

ll rsum(int l, int r)
{
	if (l == 0) return ps[r];
	return ps[r] - ps[l - 1];
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> k;
	a.resize(n);
	ps.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i == 0) ps[i] = a[i];
		else ps[i] = a[i] + ps[i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l = 0, r = min(i, (n - i)/2) + 1;
		while (l + 1 < r)
		{
			int mid = (l + r) >> 1;
			if (rsum(i - mid, i - 1) <= k && rsum(i, i + mid - 1) <= k) l = mid;
			else r = mid;
		}
		int ans1 = l;

		l = 0;
		r = min(i, (n - i) / 2) + 1;
		while (l + 1 < r)
		{
			int mid = (l + r) >> 1;
			if (rsum(i - mid, i - 1) <= k && rsum(i, i + 2 * mid - 1) <= 2 * k) l = mid;
			else r = mid;
		}
		int ans2 = l;

		for (int j = min(ans1,ans2); j >= 0; j--)
		{
			if (rsum(i - j, i - 1) <= k && rsum(i, i + j - 1) <= k && rsum(i + j, i + 2 * j - 1) <= k)
			{
				ans = max(ans, j);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}