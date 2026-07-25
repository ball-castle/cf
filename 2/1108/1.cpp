#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll a[100010];

void solve() {
    ll n;
    cin >> n;
    
    for(ll i = 1; i <= n - 1; i++) a[i] = i + 1;
    a[n] = 1;
    for(ll i = 1; i <= n; i++) cout << a[i] << ' ';
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