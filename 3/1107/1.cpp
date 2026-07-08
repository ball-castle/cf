#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*

*/


void solve() {
    ll x, y;
    cin >> x >> y;

    cout << ((x % y == 0) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0; 
}