#include<bits/stdc++.h>

using namespace std;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	int t = abs(n - m) + k;
	for (int i = 1; i < m * n; i++)
	{
		int now = n * m - i;
		if (now - 1 < t)break;
		int div = (int)sqrt(now);
		while (true)
		{
			if (now % div == 0)break;
			--div;
		}
		if (abs(div - now / div) > t)
		{
			cout << i-1;
			return 0;
		}
	}
	cout << n * m - 1;
	return 0;
}