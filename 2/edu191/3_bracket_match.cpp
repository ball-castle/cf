#include <bits/stdc++.h>
using namespace std;

using ll = long long;


/*
子序列是可以不连续的
所以就是让配对的尽可能少


*/
void solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;

    ll need = n - k; // 需要保留多少个字符

    ll cur = 0;
    ll mn = 0;
    ll p = 0;

    for(ll i = 0; i < n; i++) {
        if(s[i] == '(') cur++;
        else cur--;

        if(cur < mn) {
            mn = cur;
            p = i + 1;
        }
    }

    vector<int> ans(n, 1); // 1 表示删除，0 表示保留

    for(ll i = 0; i < p; i++) {
        if(s[i] == ')' && need > 0) {
            ans[i] = 0;
            need--;
        }
    }

    for(ll i = p; i < n; i++) {
        if(s[i] == '(' && need > 0) {
            ans[i] = 0;
            need--;
        }
    }

    for(ll i = 0; i < n; i++) {
        if(ans[i] == 1 && need > 0) {
            ans[i] = 0;
            need--;
        }
    }

    for(ll i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';
}   


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    cin >> T;
    
    while(T--) {
        solve();
    }
    
    return 0;
}
