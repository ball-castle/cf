#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200010], x[200010];
void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) x[i] = 1;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    
    for(ll i = 2; i <= n; i++) x[i] = x[i] + max(a[i] - a[i - 1], 0ll);
    for(ll i = 1; i <= n; i++) cout << x[i] << ' ';
    cout << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}