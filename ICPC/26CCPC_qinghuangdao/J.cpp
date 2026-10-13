#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mx = 0;
ll id = 0;
void solve() {
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        if(a * 12 <= b) {
            ans = m / a;
        }
        else {
            ll ct = 0;
            ct = m / b;
            ll k = m - ct * b;
            ans = ct * 12 + k / a;
        }

        if(mx < ans) {
            mx = ans;
            id = i;
        }
    }

    cout << mx << ' ' << id << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}