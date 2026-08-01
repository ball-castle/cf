#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    ll n;
    cin >> n;
    ll cnt1 = 0;
    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
        if(x == 1) cnt1++;
    }
    ll mx = 0;
    ll cnt0 = 0;
    
    for(ll x : a) {
        if(x == 0) cnt0++;
        if(x == 1) mx = max(mx, cnt0);
    }
    if(n == 1 && mx == 0) {
        cout << cnt1 - 1 << '\n';
        return;
    }
    cout << cnt1 + mx << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}