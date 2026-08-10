#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
这题依旧是数量问题，输出一个数就行
对于字符串进行删除 让他成为交替的
删除也要交替

翻译条件
1 删除1 和 0相差不超过1
删除按段来 
删除策略就是一开始全部删成每段留一个，然后进行边缘删除

*/
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll n0 = 0, n1 = 0;
    for(char c : s) {
        if(c == '0') n0++;
        else n1++;
    }

    ll dn = n0 - n1;
    if(abs(dn) > 2) {
        cout << -1 << '\n';
        return;
    }
    ll L = 1;
    ll L0 = (s[0] == '0' ? 1 : 0);
    ll L1 = (s[0] == '1' ? 1 : 0);

    for(ll i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            L++;

            if(s[i] == '0') L0++;
            else L1++;
        }
    }
    ll dL = L0 - L1;
    ll ans = (n - L) + max(0ll, abs(dn - dL) - 1);
    cout << ans << '\n';
}
    


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}