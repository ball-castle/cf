#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}



void solve() {
    ll n;
    n = read();
    ll ans = 0;
    ll m = 0;
    while(1) {
        ans += n / 2;
        m += n / 2;
        if(n >= 2) n = n - n / 2;
        ans += m / 2;
        if(m >= 2) m = m - m / 2;
        if(n == 1 && m == 1) {ans += 1; break;}
    }
    cout << ans << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    T = read();
    while(T--) solve();
    return 0;    
}