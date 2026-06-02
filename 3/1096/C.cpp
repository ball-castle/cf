#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2227
可以证明6放在最左和最右边没问题
*/


ll a[200010], b[200010];
void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) b[i] = 0;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll l = 1, r = n;
    for(ll i = 1; i <= n; i++) if(a[i] % 6 == 0) b[l] = a[i], l++;
    for(ll i = 1; i <= n; i++) if(a[i] % 2 == 0 && a[i] % 3 != 0) b[l] = a[i], l++;
    for(ll i = 1; i <= n; i++) {
        if(a[i] % 3 == 0 && a[i] % 2 != 0) b[r] = a[i], r--;
        if(a[i] % 2 != 0 && a[i] % 3 != 0) b[l] = a[i], l++; 
    }   
    for(ll i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}