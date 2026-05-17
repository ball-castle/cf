#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1] 
// dp[i][k] 就是在k的情况下b[i]的值

int mod = 998244353;

int add(int x, int y, int p = mod) {
    return ((x + y) % p + p) % p;
}

int mul(int x, int y, int p = mod) {
    return (x * 1ll * y) % p;
}



vector<int> psum(vector<int> v) {
    vector<int> ans(1, 0);
    for(auto x : v) ans.push_back(add(ans.back(), x));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y, m, k;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    cin >> x >> y >> m >> k;
    for(int i = 1; i < n; i++) a[i] = add(mul(a[i - 1], x, m), y, m);

    for(int i = 0; i <= k; i++) a = psum(a);
    ll ans = 0;

    for(int i = 1; i <= n; i++) ans ^= (a[i + 1] * 1ll * i);
    cout << ans << '\n';
    return 0;
}
    