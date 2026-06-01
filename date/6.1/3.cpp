#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
https://codeforces.com/contest/2050/problem/F
ST表
*/

ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}


ll a[200010], b[200010];
ll st[200010][20];//st[i][j] 从i开始长度为2 ^ j的gcd
ll lg[200010];
void solve() {
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) b[i] = abs(a[i] - a[i - 1]), st[i][0] = b[i];
    
    for(ll j = 1; (1 << j) <= n; j++) { // 外层是层数，内层是起点
        for(ll i = 2; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }     
    }
    while(q--) {
        ll l, r;
        cin >> l >> r; // b[l + 1], b[r]
        if(l == r) {cout << 0 << ' '; continue;}
        l = l + 1;
        ll k = lg[r - l + 1];
        ll ans = gcd(st[l][k], st[r - (1 << k) + 1][k]);
        cout << ans << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    lg[1] = 0;
    for(ll i = 2; i <= 200005; i++) lg[i] = lg[i / 2] + 1;
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}