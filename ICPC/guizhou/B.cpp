#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll a[200010];


void solve() {
    ll n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    while(q--) {
        ll x, v;
        cin >> x >> v;
        if(x == 0) continue;
        a[x] = max(a[x], v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();

    return 0;
}