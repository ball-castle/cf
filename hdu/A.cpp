#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*

*/
void solve() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;

    ll f = min(a, b);
    ll d = n / m;
    if(f < d * d) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int T;
    cin >> T;
    while(T--) solve();    
    return 0;
}