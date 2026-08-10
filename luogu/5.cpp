#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
/*
对于一个字符串它的价值可以从它下一位的总和得到
对于字符串变成dp 
dp[i] 表示i对应的这个二进制的字符串的价值

*/

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll S = 1 << n;
    vector<ll> dp(S);

    dp[0] = 1;

    for(ll m = 1; m < S; m++) {
        ll last = -1;
        for(ll i = 0; i < n; i++) {
            if(!(m >> i & 1)) continue;
            if(last == -1 || s[i] != s[last]) {
                ll pre = m ^ (1 << i);

                dp[m] += dp[pre];
                dp[m] %= mod;
            }
            last = i;
        }
    }
    cout << dp[S - 1] << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
}