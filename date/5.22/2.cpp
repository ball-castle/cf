#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
考虑过程
第一步和最后一步确定

*/
const ll mod = 1e9 + 7;
ll dp[3010][3010];
char mp[3010][3010];
ll n, m;

ll solve(ll x1, ll y1, ll x2, ll y2) {
    if(mp[x1][y1] == '#') return 0;
    for(int i = 1; i <= 3005; i++) {
        for(int j = 1; j <= 3005; j++) dp[i][j] = 0;
    }

    dp[x1][y1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j] == '#') continue;
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
            dp[i][j] %= mod;
        }
    }
    return dp[x2][y2];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> mp[i][j];
    }
    
    ll ans = (solve(2, 1, n, m - 1) * solve(1, 2, n - 1, m) % mod - solve(2, 1, n - 1, m) * solve(1, 2, n, m - 1) % mod + mod) % mod;
    cout << ans << '\n';
    return 0;

}