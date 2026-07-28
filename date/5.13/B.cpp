#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, u, r;
ll a[100], b[100], k[100], p[100], t[100];
/*
brute force -> dfs


*/
ll ans = -4e18;
void dfs(ll d, ll l) {
    if((u - d) % 2 == 0) {
        ll res = 0;
        for(int i = 1; i <= n; i++) res += a[i] * k[i];
        ans = max(ans, res);
    }
    
    if(d == u) return;

    if(!l) {
        for(int i = 1; i <= n; i++) a[i] ^= b[i];
        dfs(d + 1, 1);
        for(int i = 1; i <= n; i++) a[i] ^= b[i];
    }

    for(int i = 1; i <= n; i++) t[i] = a[p[i]] + r;
    for(int i = 1; i <= n; i++) a[i] = t[i];
    dfs(d + 1, 0);
    for(int i = 1; i <= n; i++) t[p[i]] = a[i] - r;
    for(int i = 1; i <= n; i++) a[i] = t[i];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> u >> r;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> k[i];
    for(int i = 1; i <= n; i++) cin >> p[i];

    dfs(0, 0);

    cout << ans << '\n';
    return 0;
}