#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long ll;

void queue_push(queue<tuple<int, int, int>> &q, set<pair<int, int>> &visit, int x, int y, int nx, int ny, int h, int w,
                int d) {
    if (x < 1 || y < 1 || x > h || y > w) return;
    if (visit.find({nx, ny}) != visit.end()) return;
    if (x == nx && y == ny) return;
    visit.insert({nx, ny});
    q.push({nx, ny, d + 1});
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    int sx, sy, gx, gy;
    cin >> h >> w >> n >> sx >> sy >> gx >> gy;

    map<int, vector<int>> obs_x, obs_y;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (obs_x.find(x) == obs_x.end())
            obs_x[x] = vector<int>();
        if (obs_y.find(y) == obs_y.end())
            obs_y[y] = vector<int>();

        obs_x[x].push_back(y);
        obs_y[y].push_back(x);
    }
    for (auto it = obs_x.begin(); it != obs_x.end(); ++it) {
        it->second.push_back(-2);
        it->second.push_back(w + 2);
        sort(it->second.begin(), it->second.end());
    }
    for (auto it = obs_y.begin(); it != obs_y.end(); ++it) {
        it->second.push_back(-2);
        it->second.push_back(h + 2);
        sort(it->second.begin(), it->second.end());
    }

    set<pair<int, int>> visit;
    visit.insert({sx, sy});
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});

    while (!q.empty()) {
        auto f = q.front();
        int x = get<0>(f), y = get<1>(f), d = get<2>(f);

        q.pop();
        if (x == gx && y == gy) {
            cout << d;
            return 0;
        }
        int nx, ny;
        if (obs_x.find(x) != obs_x.end()) {
            nx = x;
            ny = *(lower_bound(obs_x[x].begin(), obs_x[x].end(), y) - 1) + 1;
            queue_push(q, visit, x, y, nx, ny, h, w, d);

            ny = *upper_bound(obs_x[x].begin(), obs_x[x].end(), y) - 1;
            queue_push(q, visit, x, y, nx, ny, h, w, d);
        }
        if (obs_y.find(y) != obs_y.end()) {
            ny = y;
            nx = (*(lower_bound(obs_y[y].begin(), obs_y[y].end(), x) - 1)) + 1;
            queue_push(q, visit, x, y, nx, ny, h, w, d);

            nx = *upper_bound(obs_y[y].begin(), obs_y[y].end(), x) - 1;
            queue_push(q, visit, x, y, nx, ny, h, w, d);
        }
    }
    cout << -1;
    return 0;
}