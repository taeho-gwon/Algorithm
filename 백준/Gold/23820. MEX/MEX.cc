#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n;
	const int MP = 2000003;
	cin >> n;
	vector<int> p(MP), a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(begin(a), end(a));
	a.erase(unique(begin(a), end(a)), end(a));
	if (a[0] != 0)
	{
		cout << 0;
		return 0;
	}

	for(auto num1 : a)
	{
		for (auto num2 : a)
		{
			if (num1 * num2 > MP) break;
			p[num1 * num2] = 1;
		}
	}

	for (int i = 1; i < MP; i++)
	{
		if (p[i] == 0)
		{
			cout << i;
			return 0;
		}
	}
	cout << MP;
	return 0;
}