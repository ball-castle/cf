#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
操作是先移除再交换
只能进行一次交换
操作怎么进行
依旧是连续段的题目
一步一步分析性质

交换的操作只能影响一次   +2 / +1
思路很简单，但是我代码实现太弱
*/
void solve() {
    ll n;
    cin >> n;
    
    vector<ll> a(n), b;
    vector<ll> len;
    for(ll i = 0; i < n; i++) cin >> a[i];

    for(ll x : a) {
        if(b.empty() || b.back() != x) {
            b.push_back(x);
            len.push_back(1);
        }
        else {
            len.back()++;
        }
    }

    ll m = b.size();
    ll ans = m;
    for(ll i = 0; i + 1 < m; i++) {
        if(len[i] >= 2 && len[i + 1] >= 2) {
            ans = m + 2;
            cout << ans << '\n';
            return;
        }
    }

    for(ll i = 0; i < m; i++) {
        if(len[i] < 2) continue;
        bool ok = 0;
        
        if(i + 1 < m) {
            if(i + 2 >= m || b[i] != b[i + 2]) {
                ok = 1;
            }
        }
        if(i - 1 >= 0) {
            if(i - 2 < 0 || b[i] != b[i - 2]) {
                ok = 1;
            }
        }

        if(ok) {
            ans = m + 1;
            cout << ans << '\n';
            return;
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
