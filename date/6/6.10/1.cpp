#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a[100010];

void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll ct1 = 0, ct2 = 0;
    for(ll i = 1; i <= n; i++) if(a[i] == 2) ct1++;
    if(ct1 % 2 == 1) {
        cout << -1 << '\n';
        return;
    } 
    for(ll i = 1; i <= n; i++) {
        if(a[i] == 2) ct2++;
        if(ct2 == ct1 / 2) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}