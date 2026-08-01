#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
4
a b c d
4 1 2 3x
    3  x  
*/

void solve() {
    ll n;
    cin >> n;
    if(n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    cout << n << '\n';
    for(ll i = 1; i <= n - 1; i++) cout << i << ' ';
    cout << '\n';  
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}