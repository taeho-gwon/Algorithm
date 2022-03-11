#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> a[501];

bool isok(int a0, int a1)
{
	for (int i = 2; i <= n; i++)
	{
		int loc = a0 + (a1-a0) * i, j;
		for (j = 0; j < n && a[i][j] != loc; j++);
		if (j == n) return false;
	}
	return true;
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	vector< pair<int, int> > ans(n);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isok(a[0][i], a[1][j]))
			{
				ans[i] = { a[0][i], a[1][j] - a[0][i] };
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < n; i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}