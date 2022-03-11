#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ans;
vector<int> num;
void f(int now)
{
	if (now == n) return;
	if (ans.size() == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[ans[i]] << " ";
		}
		cout << "\n";
		return;
	}
	ans.push_back(now);
	f(now);
	ans.pop_back();
	f(now + 1);
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	num.resize(n);
	for (int i = 0; i < n; i++)cin >> num[i];
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	n = num.size();
	f(0);
	return 0;
}