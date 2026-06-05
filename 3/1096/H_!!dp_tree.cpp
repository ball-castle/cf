#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*


*/

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}



ll n;
ll dp[200010], ct[200010], mx[200010];
// ct[i] 记录以i为根的子树中，一共有多少叶子结点
// mx[i] 表示在i的子树中去掉一个点可以产生的最大价值
/*
代码就是看每个点作为根节点和他的父这条边是否使用
其实关于树上dfs这种，当一个结点的子树考虑完了就可以视作只有那个根节点了
对于每个点我们都关注它和父连的这条边，这条边最多用一次

*/

vector<ll> g[200010];

void dfs(ll u, ll fa) {
    if(g[u].size() == 1 && u != 1) ct[u] = 1;
    else ct[u] = 0;
    mx[u] = 0; 
    for(ll v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        ct[u] += ct[v];

        ll w = (ct[v] % 2 != 0) ? 1 : -1; // 这个如果是奇数
        mx[u] = max(mx[u], mx[v] + w); // 删掉点可以产生的最大值
    }
}



void solve() {
    n = read();
    for(ll i = 1; i <= n; i++) g[i].clear(), ct[i] = 0, mx[i] = 0;
    for(ll i = 1; i <= n - 1; i++) {
        ll u, v;
        u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    dfs(1, 0);
    if(g[1].size() == 1) ct[1]++; // 1只是影响奇偶，在枚举边的时候并不影响  

    ll ans = 0;
    for(ll i = 2; i <= n; i++) if(ct[i] % 2 != 0) ans++; // 枚举的是边

    if(ct[1] % 2 == 0) cout << ans << '\n';
    else cout << ans - mx[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    T = read();
    while(T--) solve();
    return 0;
}