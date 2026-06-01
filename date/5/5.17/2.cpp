#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1e9 + 7;
using M = vector<vector<ll>> ;

/*
https://codeforces.com/problemset/problem/1182/E
推系数 矩阵快速幂
将正常的递推用矩阵表示 还是 n -> n + 1
费马小定理
a ^ (p - 1) mod p == 1
a 不被p整除
*/

M mul(M a, M b, ll mod) {
    ll n = a.size();
    M c(n, vector<ll> (n, 0));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            if(a[i][k] == 0) continue;
            for(int j = 0; j < n; j++) c[i][j] = (c[i][j] + a[i][k] % mod * b[k][j] % mod) % mod;
        }
    }

    return c;
}

M mksm(M a, ll b, ll mod) {
    int n = a.size();

    M ans(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) ans[i][i] = 1;
    while(b) {
        if(b & 1) ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return ans;
}

ll ksm(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    M T = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };

    M a = mksm(T, n - 3, Mod - 1);

    // 求出系数对应最终的矩阵的什么部分
    ll e1 = a[0][2];
    ll e2 = a[0][1];
    ll e3 = a[0][0];

    M C = {
        {1, 1, 1, 2, Mod - 5},
        {1, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1}
    };

    vector<ll> in = {0, 0, 0, 3, 1};

    M b = mksm(C, n - 3, Mod - 1);
    ll ec = 0;
    for(int i = 0; i < 5; i++) ec = (ec + b[0][i] * in[i]) % (Mod - 1); 

    ll ans = 1;
    ans = ans * ksm(f1, e1, Mod), ans %= Mod;
    ans = ans * ksm(f2, e2, Mod), ans %= Mod;
    ans = ans * ksm(f3, e3, Mod), ans %= Mod;
    ans = ans * ksm(c, ec, Mod), ans %= Mod;

    cout << ans << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    while(T--) solve();
    return 0;
}