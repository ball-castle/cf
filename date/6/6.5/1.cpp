#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

// 计数问题


void solve() {
    ll n;
    n = read();
    vector<ll> ct(n + 1);
    for(ll i = 1; i <= n - 1; i++) {
        ll u, v;
        u = read(), v = read();
        ct[u]++, ct[v]++;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) ans += ct[i] * (ct[i] - 1) / 2;
    cout << ans << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    // T = read();
    while(T--) {
        solve();
    }
    
    return 0;
}
