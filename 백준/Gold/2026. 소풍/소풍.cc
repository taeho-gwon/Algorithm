#include <bits/stdc++.h>
using namespace std;

int k,n,f;
int adj[1000][1000];
vector<int> ans;
bool chk(int id)
{
    for(int num: ans)
    {
        if(!adj[id][num]) return false;
    }
    return true;
}
bool dfs(int cnt, int id)
{
    if(cnt==k)
    {
        for(int num: ans) cout<<num<<"\n";
        return true;
    }
    if(id > n) return false;

    for(int i=id;i<=n;i++)
    {
        if(chk(i)) {
            ans.push_back(i);
            if (dfs(cnt + 1, i + 1)) return true;
            ans.pop_back();
        }
    }
    return false;
}
int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin>>k>>n>>f;

    for(int i=0;i<f;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x][y]=adj[y][x]=1;
    }
    if(!dfs(0, 1))
    {
        cout<<-1;
    }
}