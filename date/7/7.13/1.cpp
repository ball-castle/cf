#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
首先它肯定是满足二分答案的，因为具有单调性
贪心让前面更小


*/



void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }
    
    auto check = [&](ll x) -> bool {
        ll pre = 0;

        for(ll v : a) {
            if(v <= pre) {
                if(pre - v > x) {
                    return 0;
                }
            }
            else {
                ll c = m - v + pre;
                if(c > x) {
                    pre = v;
                }
            }
        }
        return 1;
    };
    ll l = 0, r = m - 1;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}