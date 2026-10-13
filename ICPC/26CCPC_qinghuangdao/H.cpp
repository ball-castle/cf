#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll pre[1000010][30];


void solve() {
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    s = ' ' + s;
    for(ll i = 1; i <= n; i++) {
        ll m = s[i] - 'a' + 1;
        for(ll j = 1; j <= 26; j++) {
            pre[i][j] = pre[i - 1][j] + (j == m);
        }        
    }

    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll mx = 0;
        for(ll i = 1; i <= 26; i++) {
            ll ct = pre[r][i] - pre[l - 1][i];
            mx = max(mx, ct);
        }
        cout << mx << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}