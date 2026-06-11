#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}



void solve() {
    vector<ll> a(7);
    for(ll i = 0; i < 7; i++) {
        a[i] = read();
    }
    sort(a.begin(), a.end());
    ll ans = a[6];
    for(ll i = 0; i < 6; i++) ans += (-1) * a[i];
    cout << ans << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    T = read();
    while(T--) {
        solve();
    }
    
    return 0;
}
