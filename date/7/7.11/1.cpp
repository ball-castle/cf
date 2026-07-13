#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll t, s, x;
    cin >> t >> s >> x;
    if(x == t) {
        cout << "YES" << '\n';
        return;
    }

    if(x < t) {
        cout << "NO" << '\n';
        return;
    }

    x = x - t;
    ll m = x / s;
    if(m == 0) {
        cout << "NO" << '\n';
        return;
    }
    if(m * s == x || m * s + 1 == x) {
        cout << "YES" << '\n';
        return;
    }

    cout << "NO" << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}