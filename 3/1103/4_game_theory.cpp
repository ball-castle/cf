#include <bits/stdc++.h>
using namespace std;

using ll = long long;


/*
枚举dp 每个位置是否必胜 然后去更新
*/
ll a[200010], ct[200010], win[200010];
void solve() {
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= 20000; i++) ct[i] = 0, win[i] = 0;
    for(ll i = 1; i <= n; i++) cin >> a[i], ct[a[i]]++;
    set<ll> lose;
    ll f = 0;
    for(ll i = n; i >= 1; i--) { // 枚举x
        if(ct[i] == 0) continue;

        auto it = lose.lower_bound(i + 1);
        ll hl = 0;
        if(it != lose.end() && *it <= min(n, i + k)) hl = 1;
        
        if(hl) win[i] = 1;
        else {
            if(ct[i] % 2 == 0) win[i] = 1;
            else {
                win[i] = 0;
                lose.insert(i);
            } 
        }
        if(win[i]) f = 1;
    }
    cout << (f ? "YES" : "NO") << '\n';
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
