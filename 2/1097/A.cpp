#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[200010];
void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    
    ll sum = 0, ans = 0;
    for(ll i = n; i >= 1; i--) {
        if(sum + a[i] > 0) ans++, sum += a[i];
        else sum = 0;
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