#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

const ll mod = 676767677;

/*
模拟的想法是算法最基础的想法
认真读题
计数问题
一个人在t = b[i]时候坐下说明在这个时刻它同时满足两个条件
1.至少a[i]个人已经坐下
2.邻居坐下了                   
对于我们这个t 我们看 如果邻居还没坐下 那直接没戏
如果刚好在这个点坐下 我们
*/

ll b[200010], ct[200010], p[200010];

void solve() {
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i <= 200000; i++) b[i] = 0, ct[i] = 0;
    for(ll i = 0; i < n; i++) cin >> b[i], ct[b[i]]++; // ct[i] 表示i时刻有多少人坐下

    for(ll i = 0; i < m; i++) p[i + 1] = p[i] + ct[i]; // p[i] 表示i之前有多少人坐下

    ll ans = 1;

    for(ll i = 0; i < n; i++) {
        if(b[i] > 0) {
            ll t = 4e18;

            if(i - 1 >= 0) {
                t = min(t, b[i - 1]);
            } 
            if(i + 1 < n) {
                t = min(t, b[i + 1]); // t为左右邻居的最早坐下时间
            }

            if(t != 4e18) t++; // 邻居后一个的时间
            if(b[i] > t) ans = ans * ct[b[i] - 1] % mod; // 等自己人数到才能坐下 p[b[i] - 1] < a[i] <= p[b[i]]
            else if(b[i] == t) ans = ans * p[b[i]] % mod; //到了b[i]邻居刚好满足 a[i] <= p[b[i]]
            else ans = 0;
        }
    }
    cout << ans << '\n';
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
