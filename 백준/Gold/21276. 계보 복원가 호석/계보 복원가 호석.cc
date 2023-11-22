#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n;
    cin>>n;
    vector<string> s(n);
    vector<int> indeg(n);
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s.begin(), s.end());

    map<string, int> mp;
    for(int i=0;i<n;i++) mp[s[i]] = i;

    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        string c, p;
        cin>>c>>p;
        adj[mp[p]].push_back(mp[c]);
        indeg[mp[c]]++;
    }

    queue<int> q;
    vector<int> roots;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            roots.push_back(i);
            q.push(i);
        }
    }

    vector<vector<int>> ans(n);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int nxt: adj[f])
        {
            indeg[nxt]--;
            if(indeg[nxt]==0)
            {
                ans[f].push_back(nxt);
                q.push(nxt);
            }
        }
    }

    cout<< roots.size() <<"\n";
    for(int root: roots) cout<<s[root]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<s[i] <<" "<<ans[i].size()<<" ";
        sort(ans[i].begin(), ans[i].end());
        for(int child: ans[i]) cout<<s[child]<<" ";
        cout<<"\n";
    }
}