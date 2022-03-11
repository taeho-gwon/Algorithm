#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, x;
    cin >> a >> b >> c >> x;
    if (x > b) {
        cout << 0;
    } else if (x <= a) {
        cout << 1;
    } else {
        cout << setprecision(10) << (double) c / (b - a);
    }
}