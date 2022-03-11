#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s;
}