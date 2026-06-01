#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
ll sum[200010], a[200010];
vector<int> g[100010];
ll ans = 0;


void add(ll x, ll &s1, ll &s2, ll &s3) {
    x %= mod;
    s3 = (s3 + s2 * x) % mod;
    s2 = (s2 + s1 * x) % mod;
    s1 = (s1 + x) % mod;
}


void dfs(int u, int fa) {
    ll s1 = 0, s2 = 0, s3 = 0;
    
    add(a[u], s1, s2, s3);

    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sum[u] = (sum[u] + sum[v]) % mod; // dp更新
        add(sum[v], s1, s2, s3);
    }
    ans = (ans + s3) % mod;
}


void solve() {
    int n;
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) sum[i] = 0, a[i] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] %= mod, sum[i] = a[i] ; 
    dfs(1, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}