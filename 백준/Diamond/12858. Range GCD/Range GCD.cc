#include<iostream>
#include<vector>
#define lc(i) ((i)<<1)
#define rc(i) ((i)<<1|1)

using namespace std;

typedef long long ll;
ll seg1[1<<18], seg2[1<<18];
int n,p;
ll ab(ll x){return x>0?x:-x;}
ll gcd(ll x, ll y){ return y?gcd(y,x%y):ab(x); }

ll get(int x)
{
	x+=p;
	vector<int> chk;
	for(int i=(x>>1);i>=1;i>>=1) chk.push_back(i);
	for(int i=chk.size()-1;i>=0;i--)
	{
		int t=chk[i];
		seg1[lc(t)]+=seg1[t];
		seg1[rc(t)]+=seg1[t];
		seg1[t]=0;
	}
	return seg1[x];
}

ll rgcd(int l, int r)
{
	l+=p;
	r+=p;
	ll ans=0;
	while(l<=r)
	{
		if(l&1) ans = gcd(ans, seg2[l++]);
		if(~r&1) ans = gcd(ans, seg2[r--]);
		l>>=1;
		r>>=1;
	}
	return ans;
}
void update(int x, ll v)
{
	x+=p;
	seg2[x]+=v;
	x>>=1;
	while(x)
	{
		seg2[x]=gcd(seg2[lc(x)], seg2[rc(x)]);
		x>>=1;
	}
}
void range_update(int l, int r, ll v)
{
	update(l, v);
	if(r+1<n)update(r+1, -v);
	l+=p;
	r+=p;
	while(l<=r)
	{
		if(l&1) seg1[l++]+=v;
		if(~r&1) seg1[r--]+=v;
		l>>=1;
		r>>=1;
	}

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
	cin>>n;
	for(p=n;p^(-p&p);p+=-p&p);
	for(int i=0;i<n;i++)
	{
		cin>>seg1[p+i];
		if(i) seg2[p+i] = seg1[p+i]-seg1[p+i-1];
	}
	
	for(int i=p-1;i>=1;i--) seg2[i]=gcd(seg2[lc(i)], seg2[rc(i)]);

	int m;
	cin>>m;
	while(m--)
	{
		ll t;
		int l,r;
		cin>>t>>l>>r;
		--l;
		--r;
		if(t==0) cout<<gcd(get(l), rgcd(l+1,r))<<"\n";
		else range_update(l,r,t);
	}
}