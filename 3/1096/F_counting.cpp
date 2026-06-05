#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
这种其实都算是计数问题
计数问题大都可以转化成简单的顺序或逆序计算
结果
*/

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}
ll a[200010], ct[200010];
void solve() {
    ll n;
    n = read();
    for(ll i = 1; i <= n; i++) ct[i] = 0;
    for(ll i = 1; i <= n; i++) a[i] = read(), ct[a[i]]++;
    for(ll i = n; i >= 2; i--) ct[i - 1] = ct[i] + ct[i - 1];
    ll ans = 0;
    ll begin = 0, end = 0;
    for(ll i = 1; i <= n; i++) begin += a[i] * i;
    for(ll i = 1; i <= n; i++) end += (2 * n - ct[i] + 1) * ct[i] / 2;
    // cout << begin << ' ' << end << '\n';
    ans = end - begin;
    // cout << end << ' ' << begin << '\n';

    ll mx = -4e18;
    for(ll i = 1; i <= n; i++) {
        ll m = 0;
        m = i - n + ct[a[i]] - 1;
        mx = max(mx, m);
    }
    ans += mx;
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