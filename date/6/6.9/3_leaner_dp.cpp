#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
对于线性dp
考虑加入某个数它是自己单开还是连到前面一个
有一个注意的就是dp数组的定义，按照题目特征来 
像p4310 就是由于有二进制的存在所以定义成一个二进制是否是一进行转移
dp[j]  表示上一层，也就是以 i-1 结尾的状态
这就是为什么i可以隐去，因为dp[j]已经处理了到上一层的信息
只依赖于上一层所以i可以隐去
能不能隐去 i，看的是：未来还需不需要知道具体位置。如果不需要，只需要某种状态特征，就可以隐去。

*/
ll a[300010], sum[300010], dp[100];
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i <= m - 1; i++) dp[i] = -4e18;
    ll ans = 0;
    
    for(ll i = 0; i < n; i++) {
        vector<ll> ndp(m, -4e18);
        ndp[1 % m] = max(ndp[1 % m], a[i] - k);
        
        for(ll j = 0; j < m; j++) {
            if(dp[j] != -4e18) {
                ndp[(j + 1) % m] = max(ndp[(j + 1) % m], dp[j] + a[i] - (j == 0 ? k : 0));
            }
        }
        for(ll j = 0; j < m; j++) dp[j] = ndp[j];
        for(ll j = 0; j < m; j++) ans = max(ans, dp[j]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}