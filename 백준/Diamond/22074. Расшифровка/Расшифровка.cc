#include<iostream>
#include<vector>

using namespace std;
string s;
const int SZ = 1 << 17;
string f[10];
typedef long long ll;
struct DATA {
    ll cnt[3][3];
    int l, r;
};
DATA seg[SZ << 1];
const ll MOD = 1000000007LL;

bool cmp(string &s1, int l1, string &s2) {
    for (int i = l1, j = 0; j < s2.length(); i++, j++) {
        if (s1[i] != s2[j]) return false;
    }
    return true;
}

DATA merge(DATA dl, DATA dr) {
    if (dr.l == -1) return dl;
    if (dl.l == -1) return dl;

    DATA ret;
    ret.l = dl.l;
    ret.r = dr.r;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ret.r - ret.l == i + j) ret.cnt[i][j] = 1;
            else if (ret.r - ret.l < i + j) ret.cnt[i][j] = 0;
            else ret.cnt[i][j] = (dl.cnt[i][0] * dr.cnt[0][j]) % MOD;
        }
    }


    for (int i = 0; i < 10; i++) {
        if (f[i].length() == 1) continue;
        if (f[i].length() == 2 && cmp(s, dl.r - 1, f[i])) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ret.cnt[i][j] += dl.cnt[i][1] * dr.cnt[1][j];
                    ret.cnt[i][j] %= MOD;
                }
            }
        }
        if (f[i].length() == 3 && cmp(s, dl.r - 1, f[i])) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ret.cnt[i][j] += dl.cnt[i][1] * dr.cnt[2][j];
                    ret.cnt[i][j] %= MOD;
                }
            }
        }
        if (cmp(s, dl.r - 2, f[i]) && f[i].length() == 3) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ret.cnt[i][j] += dl.cnt[i][2] * dr.cnt[1][j];
                    ret.cnt[i][j] %= MOD;
                }
            }
        }
    }
    return ret;
}

DATA create_data(int idx) {
    DATA ret;
    for (int i = 0; i < 9; i++)
        ret.cnt[i / 3][i % 3] = 0;
    if (idx == -1) {
        ret.l = ret.r = -1;
        return ret;
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (f[i].length() == 1 && f[i][0] == s[idx]) ++cnt;
    }
    ret.cnt[0][0] = cnt;
    ret.cnt[0][1] = ret.cnt[1][0] = 1;
    ret.l = idx;
    ret.r = idx + 1;

    return ret;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c >> s;
    for (int i = 0; i < 10; i++)
        f[i] = to_string(a * i * i + b * i + c);

    for (int i = 0; i < SZ; i++) {
        if (i < s.length())
            seg[SZ + i] = create_data(i);
        else
            seg[SZ + i] = create_data(-1);
    }
    for (int i = SZ - 1; i >= 1; i--) {
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
    cout << seg[1].cnt[0][0] << "\n";
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        s[l] = r + '0';
        seg[SZ + l] = create_data(l);
        for (int i = SZ + l; i > 1;) {
            i >>= 1;
            seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
        }
        cout << seg[1].cnt[0][0] << "\n";
    }

    return 0;
}