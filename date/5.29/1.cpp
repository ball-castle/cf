#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n + 1), d(n + 1);
    unordered_map<ll, ll> mp; // 位置和编号 
    for(ll i = 1; i <= n; i++) {
        cin >> a[i] >> d[i];
        mp[a[i]] = i;
    } 
    ll f = 0;
    for(ll i = 1; i <= n; i++) {
        ll t = a[i] + d[i];
        if(mp.count(t)) { // 判断键是否存在
            ll j = mp[t];
            if(a[j] + d[j] == a[i]) f = 1;
        }
    }
    
    cout << (f ? "YES" : "NO") << '\n';
    
    return 0;
}