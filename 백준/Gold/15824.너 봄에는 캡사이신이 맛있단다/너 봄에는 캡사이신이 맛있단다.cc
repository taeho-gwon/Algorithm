#include<bits/stdc++.h>
#define MOD 1000000007LL

typedef long long ll;
using namespace std;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n), p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i == 0) p[i] = 1;
		else p[i] = (p[i - 1] * 2) % MOD;
	}
	sort(a.begin(), a.end());

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll now = a[i] * (p[i] - p[n - 1 - i] + MOD) % MOD;
		ans = (ans + now) % MOD;
	}
	cout << ans;
	
	return 0;
}