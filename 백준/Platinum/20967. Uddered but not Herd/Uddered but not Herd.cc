#include<bits/stdc++.h>

using namespace std;
int alpha[26], f[1 << 20], cnt[20][20], dp[1 << 20], sm[20][1<<20], n, c, i, j;
string s;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string s;
	fill(alpha, alpha + 26, -1);
	for (i = 0; i < 20; i++) f[1 << i] = i;
	
	cin >> s;
	n = s.length();

	int previdx, idx = s[0] - 'a';
	alpha[idx] = c++;
	for (i = 1; i < n; i++)
	{
		previdx = idx;
		idx = s[i] - 'a';
		if (alpha[idx] < 0) alpha[idx] = c++;
		cnt[alpha[previdx]][alpha[idx]]++;
	}
    
	for (i = 0; i < c; i++) for (j = 1; j < 1 << c; j++)
		sm[i][j] = sm[i][j & (j - 1)] + cnt[i][f[j & -j]];

	dp[0] = 1;
	for (i = 1; i < 1 << c; i++)
	{
		dp[i] = n;
		for (j = i; j; j &= j - 1)
			dp[i] = min(dp[i], dp[i ^ (j & -j)] + sm[f[j & -j]][i]);
	}
	cout << dp[(1 << c) - 1];

	return 0;
}