#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
分析题目需要什么贪心就行
然后在这之后有个二分优化
*/

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    ll pre = -4e18;
    
    ll f = 1;

    for(auto x : a) {
        ll k = 4e18; // k为这个位置的目标值 
        if(x >= pre) k = x;
        
        auto it = lower_bound(b.begin(), b.end(), pre + x);
        if(it != b.end()) {
            k = min(k, *it - x);
        } 
        if(k == 4e18) {
            f = 0;
            break;
        }
        pre = k;
    }
    cout << (f ? "YES" : "NO") << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}