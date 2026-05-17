#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    
 
    cout << (n / 2) * min(2 * a, b)  + n % 2 * a << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}   