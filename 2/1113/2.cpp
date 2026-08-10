#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll i = 0, j = 0;
    if(n < 2 * m) {
        cout << "NO" << '\n';
        return;
    }
    for(ll i = 0; i < m; i++) {
        ll l = a[i];
        ll r = a[n - m + i];

        if(!(l < b[i] && b[i] < r)) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}