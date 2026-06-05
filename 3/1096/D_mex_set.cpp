#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2227
对于回文串的核心在于中心 尤其在于mex
mex 第一次没出现的 所以把出现的删除第一个就是
*/

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

ll n;
vector<ll> a(200010);
ll cal(ll l, ll r) {
    set<ll> s;
    for(ll i = 0; i <= 2 * n; i++) s.insert(i);

    while(l >= 0 && r < 2 * n && a[l] == a[r]) {
        s.erase(a[l]), l--, r++;
    }
    return *s.begin();
}
 
void solve() {
    n = read();

    for(ll i = 0; i < 2 * n; i++) a[i] = read();
    
    ll x = -1, y;
    for(ll i = 0; i < 2 * n; i++) {
        if(!a[i]) {
            if(x == -1) x = i;
            else y = i;
        }
    }
    cout << max(cal(x, x), max(cal(y, y), cal((x + y) / 2, (x + y + 1) / 2))) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    T = read();
    while(T--) solve();
    return 0;
}