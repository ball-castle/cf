#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t[100010];
ll n, m;
bool check(ll time) {
    ll ans = 0;
    for(ll i = 1; i <= n; i++) ans += time / t[i];
    return ans >= m;
}



void solve() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> t[i];
    ll l = 0, r = 1e18;

    ll ans = 0;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;    // 一定避免死循环
        }
    }
    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}