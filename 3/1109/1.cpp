#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    string s;
    ll n;
    cin >> n;
    cin >> s;
    ll mx = 0, len = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] == '#') len++, mx = max(mx, len);
        else {
            len = 0;
        }
    }
    if(mx == 0) {
        cout << 0 << '\n';
        return;
    }
    if(mx == 1 || mx == 2) {
        cout << 1 << '\n';
        return;
    } 
    cout << (mx + 1) / 2 << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}