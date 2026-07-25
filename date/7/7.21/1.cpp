#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
find the pattern



*/


void solve() {
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            ll x;
            cin >> x;

            if(x == 1 && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                cout << 2 << '\n';
                return;
            }
        }
    }
    cout << 4 << '\n';

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
    

}