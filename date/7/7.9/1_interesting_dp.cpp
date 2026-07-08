#include <bits/stdc++.h>
using namespace std;

/*
比较有意思的一个dp想法
基于前面是否匹配上去更新dp
最后如果可以有1那么就成立
难点在于怎么定义这个dp
*/


using ll = long long;

void solve() {
    string s;
    string t;
    cin >> s >> t;

    ll n = s.size();
    ll m = t.size();

    vector<ll> dp0(n), dp1(n); // 还没开始向左走 开始向左走了

    for(ll i = 0; i < n; i++) {
        if(s[i] == t[0]) {
            dp0[i] = 1;
        }
    }
    
    for(ll j = 1; j < m; j++) {
        vector<ll> ndp0(n), ndp1(n);
        for(ll i = 0; i < n; i++) {
            if(dp0[i]) {
                if(i + 1 < n && s[i + 1] == t[j]) {
                    ndp0[i + 1] = 1;
                }
                
                if(i - 1 >= 0 && s[i - 1] == t[j]) {
                    ndp1[i - 1] = 1;
                }
            }

            if(dp1[i]) {
                if(i - 1 >= 0 && s[i - 1] == t[j]) {
                    ndp1[i - 1] = 1;
                }
            }
        }
        dp0 = ndp0;
        dp1 = ndp1;
    }
    for(ll i = 0; i < n; i++) {
        if(dp0[i] || dp1[i]) {
            cout << "YES" << '\n';
            return;            
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    
    while(T--) {
        solve();
    }
    
    return 0;
}
