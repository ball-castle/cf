#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
void solve() {
    cin >> n;
    vector<string> a(n, string(5, '0'));
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll f = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i][0] == 'O' && a[i][1] == 'O') {a[i][0] = a[i][1] = '+', f = 1; break;}
        else if(a[i][3] == 'O' && a[i][4] == 'O') {a[i][3] = a[i][4] = '+', f = 1; break;}
    }
    if(!f) {cout << "NO" << '\n'; return;}
    cout << "YES" << '\n';
    for(ll i = 0; i < n; i++) cout << a[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // T = read();
    while(T--) solve();
    return 0;
}