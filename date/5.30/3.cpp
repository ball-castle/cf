#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/847/B
直接模拟不好写
换个思路
*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> ans;
    vector<ll> en;
    for(int i = 0; i < n; i++) {
        ll x = a[i];
        auto it = upper_bound(en.begin(), en.end(), x, [&](ll x, ll y) {return x > y;});
        if(it == en.end()) {
            en.push_back(x);
            ans.push_back({x});
            continue;
        }

        ll idx = it - en.begin();
        en[idx] = x;
        ans[idx].push_back(x); 
    }
    
    for(int i = 0; i < (int)ans.size(); i++) {
        for(int j = 0; j < (int)ans[i].size(); j++) cout << ans[i][j] << ' ';
        cout << '\n';    
    }
    return 0;
}