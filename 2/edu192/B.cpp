#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
前缀和
区间统计前缀和是一个很自然的想法

*/


ll a[200010];
ll pre1[200010], pre3[200010];


void solve() {
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) cin >> a[i];

    for(ll i = 1; i <= n; i++) {
        if(a[i] == 1) {
            pre1[i] = pre1[i - 1] + 1;
            pre3[i] = pre3[i - 1] + 1;
        }

        else if(a[i] == 2) {
            pre1[i] = pre1[i - 1] - 1;
            pre3[i] = pre3[i - 1] - 1;
        }
        
        else {
            pre1[i] = pre1[i - 1] - 1;
            pre3[i] = pre3[i - 1] + 1;
        }
    }

    // pre1[i] >= 0 pre3[y] - pre3[i] <= 0  
    for(ll i = 1; i <= n; i++) {
        
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