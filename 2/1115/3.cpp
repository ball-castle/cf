#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
一个n * m
抽走某行对上面所有行都会减去某一个值
现在需要达到两个要求之一 一个是某一行全部抽走 另一个是把一个降到0
操作次数小于m
前面max 后面取min
前面从下到上每个遍历，然后每次都去找最小的
利用队列的性质
*/

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    vector<vector<ll>> a(n, vector<ll> (m));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) cin >> a[i][j];
    }

    ll ans = m;

    priority_queue<ll, vector<ll>, greater<ll>> q; //自动排序想到小根堆
    ll sum = 0;
    for(ll i = n - 1; i >= 0; i--) {
        for(ll j = 0; j < m; j++) {
            ll x = a[i][j];

            q.push(x);
            sum += x;

            if((ll)q.size() == ans) {
                sum -= q.top();
                q.pop();
            }
        }

        if(sum >= v[i]) {

            while(!q.empty() && sum - q.top() >= v[i]) {
                sum -= q.top();
                q.pop();
            }
            ans = q.size();
            if(ans == 1) break;

            sum -= q.top();
            q.pop();
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}