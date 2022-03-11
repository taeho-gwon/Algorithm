#include<bits/stdc++.h>

using namespace std;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<long long> psum(n + 1), psqsum(n +1);
	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		psum[i] = psum[i - 1] + x;
		psqsum[i] = psqsum[i - 1] + x * x;
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		cout << ((psum[r] - psum[l]) * (psum[r] - psum[l]) - (psqsum[r] - psqsum[l])) / 2 << "\n";
	}
	return 0;
}