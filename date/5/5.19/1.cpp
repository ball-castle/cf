#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
https://codeforces.com/problemset/problem/1057/A
这题其实还没有做到树的本质难题
就是进行了一个转化，将从前往后变成了从后往前

*/
ll p[200010];
void solve() {
    ll n;
    cin >> n;

    for(ll i = 2; i <= n; i++) cin >> p[i];

    vector<ll> ans;
    int c = n;
    while(1) {
        ans.push_back(c);
        if(c == 1) break;
        c = p[c];
    }
    reverse(ans.begin(), ans.end());
    for(ll x : ans) cout << x << ' ';
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    T = 1;
    while(T--) solve();
    return 0;
}