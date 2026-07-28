#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
本质是移动棋子将他们合并
对于某一列的状态可以从前一列转移
然后存在两种状态，进行存储就行

*/

void solve() {
    ll n;
    cin >> n;

    string s[2];
    cin >> s[0] >> s[1];

    ll l = 0;
    while(s[0][l] == '.' && s[1][l] == '.') {
        l++;
    }
    ll r = n - 1;
    while(s[0][r] == '.' && s[1][r] == '.') {
        r--;
    }

    ll dp0 = (s[1][l] == '*');
    ll dp1 = (s[0][l] == '*');
    
    for(ll i = l + 1; i <= r; i++) {
        ll ndp0 = min(
            dp0 + 1 + (s[1][i] == '*'),
            dp1 + 2 
        );    
        ll ndp1 = min(
            dp1 + 1 + (s[0][i] == '*'),
            dp0 + 2
        );
        dp0 = ndp0;
        dp1 = ndp1;
    }
    cout << min(dp0, dp1);
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}