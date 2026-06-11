#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}


ll a[300010], b[300010];

/*
不要想着去构造这么多个质数
利用奇数相乘
*/

void solve() {
    ll n = read();
    for(ll i = 1; i <= n; i++) {
        cout << (i * 2 - 1) * (i * 2 + 1) << ' ';
    }
    cout << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    T = read();
    while(T--) {
        solve();
    }
    
    return 0;
}
