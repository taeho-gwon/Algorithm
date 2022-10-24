#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii dist[404][404];
const int MOD = 1000000009;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dist[i][j] = {-1, -1};
    queue<pii> q;
    q.push({1, 1});
    dist[1][1] = {0, 1};

    int flag[8][2] = {2, 1, 2, -1, -2, 1, -2, -1,
                      1, 2, 1, -2, -1, 2, -1, -2};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = flag[i][0] + x, ny = flag[i][1] + y;
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if (dist[nx][ny].first == -1) {
                dist[nx][ny] = {dist[x][y].first + 1, dist[x][y].second};
                q.push({nx, ny});
            } else if (dist[nx][ny].first == dist[x][y].first + 1) {
                dist[nx][ny].second += dist[x][y].second;
                dist[nx][ny].second %= MOD;
            }
        }
    }
    if (dist[n][m].first == -1) {
        cout << "None";
    } else {
        cout << dist[n][m].first << " " << dist[n][m].second;
    }
}