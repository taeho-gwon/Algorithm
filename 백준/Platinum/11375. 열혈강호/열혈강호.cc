#include<iostream>
#include<vector>
#include<queue>

#define INF 2000000000
using namespace std;
class Dinic
{
private:
	struct Edge
	{
		int v, cap, rev;
		Edge(int _v, int _c, int _r)
		{
			v=_v;
			cap=_c;
			rev=_r;
		}
	};
	vector< vector<Edge> > adj;
	vector<int> lev, work;
	int n;

	void bfs(int s)
	{
		lev.clear();
		lev.resize(n,-1);
		lev[s]=0;

		queue<int> q;
		q.push(s);
		while(!q.empty())
		{
			int f = q.front();
			q.pop();

			for(int i=0;i<adj[f].size();i++)
			{
				Edge& e= adj[f][i];
				if(e.cap>0 && lev[e.v]==-1)
				{
					lev[e.v] = lev[f]+1;
					q.push(e.v);
				}
			}
		}
	}
	int dfs(int v, int t,int f)
	{
		if(v==t)return f;
		for(;work[v]<adj[v].size();work[v]++)
		{
			Edge &e = adj[v][work[v]];
			if(e.cap>0 && lev[v]<lev[e.v])
			{
				int d = dfs(e.v, t, min(f, e.cap));
				if(d<=0) continue;
				e.cap -= d;
				adj[e.v][e.rev].cap +=d;
				return d;
			}
		}
		return 0;
	}
public:
	Dinic(int _n)
	{
		n=_n;
		adj.resize(n);
	}
	void addEdge(int v1, int v2, int cap)
	{
		adj[v1].push_back(Edge(v2, cap, adj[v2].size()));
		adj[v2].push_back(Edge(v1, 0, adj[v1].size()-1));
	}
	int max_flow(int s, int t)
	{
		int f = 0;
		while(1)
		{
			bfs(s);
			if(lev[t]<0) return f;
			work.clear();
			work.resize(n+1);
			int nowf;
			while(1)
			{
				nowf = dfs(s,t,INF);
				if(nowf<=0)break;
				f +=nowf;
			}
		}
		return -1;
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	Dinic d = Dinic(n+m+2);
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x--)
		{
			int y;
			cin>>y;
			d.addEdge(i, n+y, 1);
		}
	}

	for(int i=1;i<=n;i++) d.addEdge(0,i,1);
	
	for(int i=n+1;i<=n+m;i++) d.addEdge(i, n+m+1,1);

	cout<<d.max_flow(0,n+m+1);
}