#include<iostream>
#include<algorithm>
#define N 2003
#define MOD 1000000007

using namespace std;
int dp[N][N], dpb[N][3][N], n,cs,cf;

int main()
{
	cin>>n>>cs>>cf;
	if(cs>cf) cs^=cf^=cs^=cf;

	dpb[1][1][1]=1;
	dpb[2][1][1]=dpb[2][2][2]=0;
	dpb[2][1][2]=dpb[2][2][1]=1;

	for(int i=3;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=i;j>1;j--)
			{
				if(j==i) dpb[i][1][j]=0;
				else dpb[i][1][j] = (dpb[i][1][j+1] + dpb[i-1][1][j])%MOD;
			}
		}
		else
		{
			for(int j=2;j<=i;j++)
			{
				if(j==2) dpb[i][1][j]=0;
				else dpb[i][1][j] = (dpb[i][1][j-1] + dpb[i-1][1][j-1])%MOD;
			}
		}
	}

	for(int i=3;i<=n;i++) for(int j=3;j<=i;j++)
	{
		dpb[i][2][j] = (dpb[i][1][j] + dpb[i-1][1][j-1]) % MOD;
	}

	for(int i=1;i<=n;i++)
	{
		int num = i-n+cf;
		if(num<0) continue;
		for(int j=1;j<=i;j++)
		{
			if(j<=2) dp[i][j] = dpb[i][j][num];
			else
			{
				dp[i][j] = (2*dp[i][j-1])%MOD;
				dp[i][j] = (dp[i][j]-dp[i][j-2]+MOD)%MOD;
				dp[i][j] = (dp[i][j]-dp[i-2][j-2]+MOD)%MOD;
			}
		}
	}
	cout<< dp[n][cs];
}