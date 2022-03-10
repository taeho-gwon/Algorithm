#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

class Dinic {
public:
    Dinic(int n) : _n(n), _adj(n) {}

    void add_edge(int from, int to, int cap) {
        int from_id = _adj[from].size(), to_id = _adj[to].size();
        _adj[from].emplace_back(Edge{to, to_id, cap});
        _adj[to].emplace_back(Edge{from, from_id, 0});
    }

    int flow(int s, int t) {
        vector<int> lev(_n), iter(_n);
        int flow = 0, flow_limit = numeric_limits<int>::max();
        while (flow < flow_limit) {
            _bfs(lev, s, t);
            if (lev[t] == -1)break;
            fill(iter.begin(), iter.end(), 0);
            int f = _dfs(lev, iter, s, t, flow_limit - flow);
            flow += f;
        }
        return flow;
    }

private:
    struct Edge {
        int to, rev;
        int cap;
    };
    int _n;
    vector<vector<Edge>> _adj;

    void _bfs(vector<int> &lev, int s, int t) {
        fill(lev.begin(), lev.end(), -1);
        lev[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (auto e: _adj[f]) {
                if (e.cap == 0 || lev[e.to] >= 0) continue;
                lev[e.to] = lev[f] + 1;
                if (e.to == t)return;
                q.push(e.to);
            }
        }
    }

    int _dfs(vector<int> &lev, vector<int> &iter, int s, int v, int cap) {
        if (s == v) return cap;
        int res = 0;
        int lev_v = lev[v];
        for (int &i = iter[v]; i < _adj[v].size(); i++) {
            Edge &e = _adj[v][i];
            if (lev_v <= lev[e.to] || _adj[e.to][e.rev].cap == 0) continue;
            int f = _dfs(lev, iter, s, e.to, min(cap - res, _adj[e.to][e.rev].cap));
            if (f <= 0) continue;
            e.cap += f;
            _adj[e.to][e.rev].cap -= f;
            res += f;
            if (res == cap)return cap;
        }
        lev[v] = _n;
        return res;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    set<pair<int, int>> match;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            match.insert({i, j});
        }
    }

    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        --p, --q;
        w[p]++;
        match.erase({min(p, q), max(p, q)});
    }

    int remain_match = match.size();
    for (int i = 0; i < n; i++) {
        Dinic dinic(remain_match + n + 2);
        int now_win = w[i];
        int c = 0;
        for (auto e: match) {
            int p = e.first, q = e.second;
            if (p == i || q == i) now_win++;
            else {
                dinic.add_edge(0, ++c, 1);
                dinic.add_edge(c, remain_match + p + 1, 1);
                dinic.add_edge(c, remain_match + q + 1, 1);
            }
        }
        bool chk = true;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int cap = now_win - 1 - w[j];
                if (cap < 0) {
                    chk = false;
                    break;
                }
                dinic.add_edge(remain_match + j + 1, remain_match + n + 1, cap);
            }
        }
        if (chk && dinic.flow(0, remain_match + n + 1) == c)
            cout << i + 1 << "\n";
    }
    return 0;
}