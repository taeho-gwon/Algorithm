#include<bits/stdc++.h>

using namespace std;

int dp[101][5055][101];
const int MOD = 1000000007;
int main()
{
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	int h, s;
	cin>>h>>s;
        dp[1][1][0] = dp[1][1][1] = dp[1][0][0] = 1;
	dp[1][0][1] = 0;
	for(int i=2;i<=h;i++)
	{
		for(int j=0;j<=i*(i+1)/2;j++)
		{
			for(int k=i;k>=0;k--)
			{
				if(k==i) dp[i][j][k] = dp[i-1][j-k][k-1];
				else if(k==0) dp[i][j][0] = (dp[i][j][1] + dp[i-1][j][0])%MOD;
				else dp[i][j][k] = (dp[i][j][k+1] + dp[i-1][j-k][k-1])%MOD;
			}
		}
	}
	cout<<dp[h][s][0];
}