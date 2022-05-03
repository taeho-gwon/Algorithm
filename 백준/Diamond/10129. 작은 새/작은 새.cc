#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

struct deque_data
{
	int dp, a, idx;

	bool operator<(const deque_data& other) const
	{
		if (dp != other.dp) return dp < other.dp;
		if (a != other.a) return a > other.a;
		return idx > other.idx;
	}
};
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		vector<int> dp(n);

		cin >> x;
		deque<deque_data> dq;
		dp[0] = 0;
		dq.push_back({ dp[0], a[0], 0 });
		for (int i = 1; i < n; i++)
		{
			while (!dq.empty() && dq.front().idx < i - x) dq.pop_front();
			dp[i] = dq.front().dp + (dq.front().a <= a[i]);
			deque_data now{ dp[i], a[i], i };
			while (!dq.empty() && now < dq.back())dq.pop_back();
			dq.push_back(now);
		}
		cout << dp[n - 1] << "\n";
	}
	return 0;
}