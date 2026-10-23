#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ct = 0;
    ll ans = 0;

    ll l = -1, r = -1;


    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ct++;
            if(l == -1) l = i;
            r = i;
        }
    }
    if(ct == 1) {
        cout << 0 << '\n';
    }

    else if(ct == 2) {
        cout << 1 << '\n';
    }
    else {
        cout << r - l << '\n';
    }

}
 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}