#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1000];
void solve() {
    ll k, n;
    cin >> n >> k;
    ll m = 0;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] >= k) m += a[i]; 
        if(a[i] == 0 && m > 0) m -= 1, ans++;
    }
    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}