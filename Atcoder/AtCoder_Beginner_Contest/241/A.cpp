#include<iostream>
#include<vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cout << a[a[a[0]]];

    return 0;
}