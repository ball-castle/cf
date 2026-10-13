#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll tip = 1;

void solve() {
    ll n;
    cin >> n;
    ll f = 0;
    for(ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if(x % 3 != 0) {
            f = 1;
        }
    }
    cout << "Case #" << tip <<  ": ";
    tip++; 
    cout << (f ? "No" : "Yes") << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;

}