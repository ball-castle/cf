#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll d = n * n - 1;
    ll p = n * a[n] - a[1];
    ll q = n * a[1] - a[n];

    if(n * a[n] - a[1] < 0) {
        cout << "NO" << '\n';
        return;
    }
    if(n * a[1] - a[n] < 0) {
        cout << "NO" << '\n';
        return;
    }
    if((n * a[n] - a[1]) % (n * n - 1) != 0) {
        cout << "NO" << '\n';
        return;
    }
    if((n * a[1] - a[n]) % (n * n - 1) != 0) {
        cout << "NO" << '\n';
        return;
    }
    ll x = p / d;
    ll y = q / d;
    for(ll i = 1; i <= n; i++) {
        if(a[i] != x * i + y * (n - i + 1)) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}