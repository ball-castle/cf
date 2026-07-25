#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[200010];
void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n - 1; i++) {
        if(a[i] >= i) {
            ll m = a[i] - i;
            a[i + 1] += m;
            a[i] = i;
        }
        else {
            cout << "NO" << '\n';
            return;
        }
    }
    for(ll i = 1; i <= n - 1; i++) {
        if(a[i] >= a[i + 1]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}   




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}