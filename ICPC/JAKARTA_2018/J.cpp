#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;


/*
找到性质 转化成算法
每一个只跟前一个有关
15想到用数字表示




*/

vector<string> get(string s) {
    ll n = s.size();

    vector<string> v;

    for(ll mask = 1; mask < (1 << n); mask++) {
        string t;
        for(ll i = 0; i < n; i++) {
            if(mask >> i & 1) {
                t += s[i];
            }
        }
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    return v;
} 


void solve() {
    ll n;
    cin >> n;

    vector<string> s(n);

    for(ll i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<string> pre = get(s[0]);
    vector<ll> dp(pre.size()); //第i个孩子名字恰好选择x时，前i个孩子名字长度总和的最大值。

    for(ll i = 0; i < (ll)pre.size(); i++) {
        dp[i] = pre[i].size();
    }

    for(ll i = 1; i < n; i++) {
        vector<string> cur = get(s[i]);
        vector<ll> ndp(cur.size(), -4e18);
        
        ll p = 0;
        ll best = -4e18;

        for(ll j = 0; j < (ll)cur.size(); j++) {
            while(p < (ll)pre.size() && pre[p] < cur[j]) {
                best = max(best, dp[p]);
                p++;
            }
            if(best != -4e18) {
                ndp[j] = best + cur[j].size();
            }
        }
        pre = cur;
        dp = ndp;
    }
    ll ans = -INF;

    for(auto x : dp) {
        ans = max(ans, x);
    }
    if(ans == -INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }

}   
  
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}