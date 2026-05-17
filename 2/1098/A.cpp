#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll ct[10];
void solve() {
    ll n;
    cin >> n;


    for(ll i = 0; i <= 3; i++) ct[i] = 0;
    for(ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        ct[x]++;
    }

    ll ans = 0;
    ans += ct[0];

    ll m = min(ct[1], ct[2]);
    ans += m;
    ct[1] -= m;
    ct[2] -= m;

    ans += ct[1] / 3;
    ans += ct[2] / 3;

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