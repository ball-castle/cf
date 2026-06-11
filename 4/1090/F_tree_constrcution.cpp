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
发现规律 偶数肯定比奇数要多或相等 一个偶数的数 下面肯定会有一个奇数子树 所以奇数会更多或相等
这时候构造其实就应该从简单的开始弄起
掌握基本点构造
一个是单链，一个是是单点连一个点上
最后考虑个数 我们要拿出x个偶数
*/

void solve() {
    ll x, y;
    cin >> x >> y;
    ll n = x + y;
    if((x == 0 && n % 2 == 0) || n / 2 < x) {cout << "NO" << '\n'; return;}
    cout << "YES" << '\n';
    if(n % 2 == 0) {
        ll d = 2 * x;
        for(ll i = 2; i <= d; i++) cout << i - 1 << ' ' << i << '\n';
        for(ll i = d + 1; i <= n; i++) cout << i << ' ' << d << '\n';
        return;
    }
    ll d = 2 * x + 1;
    for(ll i = 2; i <= d; i++) cout << i << ' ' << i - 1 << '\n';
    for(ll i = d + 1; i <= n; i++) cout << d << ' ' << i << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}
