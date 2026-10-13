#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;


ll inv[1000005];
/*
第一想法应该有线性dp的想法 用一个二维dp去写 在i位的时候有j个颜色的情况
但是数据会爆
所以想优化

回到一个简单的情况 如果不考虑刚好k种颜色
那么是不是很简单

考虑容斥原理
*/

ll ksm(ll a, ll b) {
    ll res = 1;
    a %= mod;

    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    if(k < 0 || n < k) return 0;
    ll res = 1;
    for(ll i = 1; i <= k; i++) {
        res = res * ((n - i + 1) % mod) % mod;
        res = res * inv[i] % mod;
    }
    return res;
}
ll tip = 1;

void solve() {
    ll n, m;
    ll k;
    cin >> n >> m >> k;

    if(k > m || k > n) {
        cout << "Case #" << tip << ": 0\n";
        return;
    } 

    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}