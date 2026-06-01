#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 998244353;
ll a[100010];


void cal() {
    ll m, l, r, d;
    cin >> m >> l >> r >> d;
    if(m == 1) {
        for(int i = l; i <= r; i++) a[i] += d;
        return;
    }
    
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    while(q--) void cal();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}