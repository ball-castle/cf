#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
两面考虑
什么时候不动
让不动的减少
*/

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}
ll a[200010];
ll s[200010];
void solve() {
    ll n;
    n = read();
    for(ll i = 1; i <= n; i++) a[i] = read();
    for(ll i = 1; i <= n + 1; i++) s[i] = 4e18;
    for(ll i = n; i >= 1; i--) s[i] = min(s[i + 1], a[i]);
    ll ans = 0;
    for(ll i = 1; i <= n; i++) ans += a[i];
    for(ll i = n; i >= 1; i--) ans -= s[i];
    ll ct = 1;
    ll add = 1;
    for(ll i = n - 1; i >= 1; i--) {
        if(s[i] == s[i + 1]) ct++, add = max(add, ct);
        else ct = 1;
    }
    ans += add - 1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    T = read();
    while(T--) solve();
    return 0;
}