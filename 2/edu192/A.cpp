#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c[100];

void solve() {
    ll k;
    cin >> k;

    for(ll i = 1; i <= k; i++) cin >> c[i];
    ll f = 0;
    for(ll i = 1; i <= k; i++) {
    
        if(c[i] >= 3) {
            cout << "YES" << '\n';
            return;
        }
        if(c[i] >= 2 && f) {
            cout << "YES" << '\n';
            return;
        }
        if(c[i] >= 2) {
            f = 1; 
        }
    }
    cout << "NO" << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}