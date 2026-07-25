#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n;
    cin >> n;
     
    set<ll> s;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }   
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}