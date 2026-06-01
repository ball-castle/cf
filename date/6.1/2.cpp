#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
设未知数
把题目转化成数学问题
*/
ll a[10000];


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll i = 1, j = n;
    ll ans = 0, ans1 = 4e18;
    k = min(k, m - 1);
    for(ll x = 0; x <= k; x++) {
        i = 1, j = n;
        i += x, j -= (k - x);
        ans1 = 4e18;
        for(ll y = 0; y <= m - 1 - k; y++) {
            ll i1 = i, j1 = j;
            i1 += y;
            j1 -= (m - 1 - k - y);
            ans1 = min(ans1, max(a[i1], a[j1]));
        }
        ans = max(ans, ans1);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}