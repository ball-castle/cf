#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
流程应该是
翻译题干 发现性质 然后找到算法 然后得出结论
a[i + 1] - a[i] 
a[i + 1] - (a[i - 1] - a[i] + a[i + 1]) = a[i] - a[i - 1]
a[i - 1] - a[i] + a[i + 1] - a[i - 1] = a[i + 1] 
！！！！本质是交换差分 翻译成中文
后面就是一段一段的处理就行
*/  
ll a[200010], b[200010];

void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
    
    ll l = 2;
    
    while(l <= n) {
        ll r = l;

        while(r + 1 <= n && (b[r] + b[r + 1]) % 2 == 0) {
            r++;
        }
        
        sort(b + l, b + r + 1);
        l = r + 1;
    }


    ll cur = 0;
    for(ll i = 1; i <= n; i++) {
        cur += b[i];
        cout << cur << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}