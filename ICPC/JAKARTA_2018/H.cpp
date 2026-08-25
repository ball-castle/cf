#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;

struct node {
    ll l, r;
    ll need;
};

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n + 1);

    for(ll i = 1; i <= n; i++) cin >> p[i];

    vector<vector<pair<ll, ll>>> add(n + 2);

    for(ll i = 0; i < k; i++) {
        ll l, r, c;
        cin >> l >> r >> c;

        ll len = r - l + 1;
        ll need = (c + len + 1) / 2;   // 至少需要多少个1
        
        
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}