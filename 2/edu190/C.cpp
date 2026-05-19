#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2230/submit\
从结论出发
这题最难处理的地方是在哪
是不是单个情况
如果每个都至少有两个那么都可以直接放就行
就分析夹的时候情况如何就行
*/
void solve() {
    ll n;
    cin >> n;
    vector<ll> c(n);
    ll ct1 = 0;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) if(c[i] == 1) ct1++;
    
    ll ans = 0;
    
    if(ct1 == n) {cout << 0 << '\n'; return;}
    ll v = 0;
    if(ct1 == n - 1) {
        for(int i = 0; i < n; i++) if(c[i] != 1) v = c[i] / 2, ans += c[i];
        ans += min(v, ct1);
        if(ans < 3) {cout << 0 << '\n'; return;} 
        cout << ans << '\n';
        return;
    }

    for(int i = 0; i < n; i++) if(c[i] != 1) v += c[i] / 2 - 1, ans += c[i];
        ans += min(v, ct1);
        if(ans < 3) {cout << 0 << '\n'; return;}
        cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}