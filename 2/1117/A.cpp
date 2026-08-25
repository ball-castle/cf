#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n, m;
    cin >> n >> m;

    bool have[26] = {};

    for(ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        have[s[0] - 'a'] = 1;
    }
    bool ok = 1;
    for(ll i = 0; i < m; i++) {
        string s;
        cin >> s;

        for(char c : s) {
            if(!have[c - 'A']) {
                ok = 0;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}