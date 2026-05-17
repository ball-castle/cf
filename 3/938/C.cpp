#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
模拟优先考虑数字处理
*/
ll a[200010];
void solve() {
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    for(ll i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    if(sum <= k) {cout << n << '\n'; return;}

    ll la = (k + 1) / 2, ra = k / 2;

    ll ans = 0;
    ll l = 1, r = n;
    while(l <= r && la >= a[l]) ans++, la -= a[l], l++;
    while(l <= r && ra >= a[r]) ans++, ra -= a[r], r--;

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