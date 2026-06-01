#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, z;
    ll a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if(x > a) {cout << "NO" << '\n'; return 0;}
    a = a - x;
    if(y > a + b) {cout << "NO" << '\n'; return 0;}
    b = b - max(0ll, (y - a)), a = max(0ll, a - y);
    if(z > a + b + c) {cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';
    return 0;
}