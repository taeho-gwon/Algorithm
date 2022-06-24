#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll mpow(ll x, ll y)
{
	if (y == 0) return 1LL;
	ll ret = mpow(x, y >> 1);
	ret = (ret * ret) % MOD;
	if (y & 1) ret = (ret * x) % MOD;
	return ret;
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	const int N = 10000000;
	vector<ll> p, is_p(N + 1);
	for (int i = 2; i <= N; i++)
	{
		if (!is_p[i])p.push_back(i);

		for (auto j : p)
		{
			if (i * j > N)break;
			is_p[i * j] = j;
			if (i % j == 0)break;
		}
	}
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		
		ll ans = 1;
		for (auto prime : p)
		{
			if (prime * 2 > n)break;
			int now = 0;
			for (int i = n / prime; i; i /= prime)
				now += i;
			now = now / 2 * 2;
			ans *= mpow(prime, now);
			ans %= MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}