#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f[10];
ll l[10];
ll st[10];


void solve() {
    ll n;
    cin >> n;

    string s[4];
    for(int i = 0; i < 4; i++) cin >> s[i];

    for(int i = 0; i < 4; i++) l[i] = 2000, st[i] = 0, f[i] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            if(s[j][i] == 'H') st[j]++;
            if(s[j][i] == 'J') l[j] -= 50, st[j] = 0;
            if(s[j][i] == 'A') l[j] -= 100, st[j] = 0;
            if(s[j][i] == 'M') l[j] -= 200, st[j] = 0;
            if(s[j][i] == 'C') st[j] = 0;
            if(st[j] == 100) {
                l[j] -= 30;
                for(ll k = 0; k < 4; k++) l[k] += 30;
                st[j] = 0;
            }
        }
        for(ll j = 0; j < 4; j++) {
            if(l[j] <= 0) f[j] = 1;
        }
        for(ll j = 0; j < 4; j++) {
            if(l[j] >= 2000) l[j] = 2000;
        }
    }
    for(ll i = 0; i < 4; i++) if(f[i]) l[i] = 0;
    for(ll i = 0; i < 4; i++) cout << l[i] << ' ';
    cout << '\n';

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;

    while(T--) solve();
}