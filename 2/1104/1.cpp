#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;


void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll mi = INF;
    for(ll i = 0; i < n; i++) {
        mi = min(a[i], mi);
        if(i != n - 1) a[i + 1] = min(a[i + 1], mi);       
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) ans += a[i];
    cout << ans << '\n'; 
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;
    while(T--) solve();


    return 0;
}