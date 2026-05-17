#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[300000], b[300000];
ll m[510][510];
void solve() {
    ll n, c, d;
    cin >> n >> c >> d;
    for(ll i = 1; i <= n * n; i++) cin >> b[i];
    sort(b + 1, b + n * n + 1);
    
    m[1][1] = b[1];
    
    for(ll i = 2; i <= n; i++) m[i][1] = m[i - 1][1] + c; 


    for(ll i = 1; i <= n; i++) {
        for(ll j = 2; j <= n; j++) m[i][j] = m[i][j - 1] + d;
    }
    ll tip = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) a[tip] = m[i][j], tip++;
    }

    sort(a + 1, a + n * n + 1);
    ll f = 0;
    for(ll i = 1; i <= n * n; i++) if(a[i] != b[i]) f = 1;
    cout << (!f ? "YES" : "NO") << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}   