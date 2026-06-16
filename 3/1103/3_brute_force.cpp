#include <bits/stdc++.h>
using namespace std;

using ll = long long;


/*
暴力的想法必须要有 枚举所有情况减少思考
*/
ll va[200010], vb[200010];


void solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll ta = 1;
    while(1) {
        va[ta] = a;
        if(a == 0) break;
        ta++, a = a / x;
    }
    ll tb = 1;
    while(1) {
        vb[tb] = b;
        if(b == 0) break;
        tb++, b = b / x;
    }

    ll ans = 4e18;
    for(ll i = 1; i <= ta; i++) {
        for(ll j = 1; j <= tb; j++) {
            ans = min(ans, i + j - 2 + abs(va[i] - vb[j]));
        }
    }
    cout << ans << '\n';

}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    cin >> T;
    
    while(T--) {
        solve();
    }
    
    return 0;
}
