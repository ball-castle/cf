#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 就是纯模拟 把0的情况单独考虑 其他就是正常的从大到小减就是了


ll tip = 1;
void solve() {
    ll a, b;
    cin >> a >> b;
    
    if(a < b) swap(a, b); 
    ll ans;
    if(b == 0) {
        ans = (a == 0 ? 1 : 2);
    }
    else {
        ans = 1;

        while(b != 0) {
            ans += a / b;

            ll r = a % b;
            a = b;
            b = r;
        }
    }
    cout << "Case #" << tip << ": " << ans << '\n';
    tip++;
    
}
/*
2
7 4
3 5
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}