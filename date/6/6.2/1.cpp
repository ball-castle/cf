#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2227
可以证明6放在最左和最右边没问题
*/

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

void solve() {
    ll n;
    n = read();
    ll ans = 1;
    for(ll i = 1; i <= 5; i++) ans *= (n + 1 - i);
    ans = ans / 120;
    ans = ans * ans * 120;
    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // T = read();
    while(T--) solve();
    return 0;
}