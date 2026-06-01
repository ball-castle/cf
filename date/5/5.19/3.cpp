#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
https://codeforces.com/problemset/problem/1942/E
博弈的问题很讲究转化
想一下这题的核心矛盾在哪个点上（博弈论需要看核心矛盾点）
创造有利条件
是不是两种不同的距离的牛上，如果距离很近肯定不利
这时候由于两两不同，两两配对
就看他们之间的间距
接下来相当于有n堆，每次我可以选择n堆进行减一
这个博弈的话就是都是偶数，必败，对方可以一直维持奇偶不变到最后0
接下来就是计算 总方案数减去 全部都是偶数，先手必胜
*/

const ll mod = 998244353;

ll fac[2000005], ifac[2000005];


ll ksm(ll a, ll b) {
    ll ans = 1;
    a %= mod;

    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}

ll ncr(ll n, ll r) {
    if(n < 0 || r < 0 || r > n) return 0;
    return fac[n] * ifac[r] % mod * ifac[n - r] % mod;
}

void init() {
    fac[0] = 1;
    for(int i = 1; i < 2000005; i++) fac[i] = fac[i - 1] * i % mod;

    ifac[2000004] = ksm(fac[2000004], mod - 2);
    for(int i = 2000003; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

void solve() {
    ll l, n;
    cin >> l >> n;

    ll m = l - 2 * n;

    ll all = 2 * ncr(l, 2 * n) % mod;
    ll bad = 0;

    for(ll s = 0; s <= m; s += 2) {
        ll in = ncr(s / 2 + n - 1, n - 1);
        ll out = ncr(m - s + n, n);

        bad = (bad + 2 * in % mod * out % mod) % mod;
    }

    cout << (all - bad + mod) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    int T;
    cin >> T;

    while(T--) solve();

    return 0;
}