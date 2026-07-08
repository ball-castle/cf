#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
对于某个j 每个a[i]中最小序号的应该被选出 否则会多产生一个逆序对

*/

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for(ll i = 0; i < n; i++) cin >> b[i];
    
    
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;
    while(T--) solve();
    return 0;

}