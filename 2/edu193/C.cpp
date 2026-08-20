#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
矩阵赋值   求和最大
think time 5min  no ieda

先来看理想操作 
我们想要留下   n + m个数
但是不可能 比如只有一个格子的时候就不太行
！！！！代码的开始是性质和操作  需要想象力和模拟
从小样例开始推起
最多有多少个数可以保留   n + m - 1
A 里面只能取 n个  B 只能取 m个 两个共有的可以随便取 满足总数量就行

*/
void solve() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(x), b(y);
    for(int i = 0; i < x; i++) cin >> a[i];
    for(int i = 0; i < y; i++) cin >> b[i];
    
   

    vector<ll> a1, b1, both, c;
    ll i = 0, j = 0;

    while(i < x && j < y) {
        if(a[i] < b[j]) {
            a1.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]) {
            b1.push_back(b[j]);
            j++;
        }
        else both.push_back(b[j]), i++, j++;
    }

    while(i < x) a1.push_back(a[i]), i++;
    while(j < y) b1.push_back(b[j]), j++;

    for(ll i = max(0ll, (ll)a1.size() - n); i < (ll)a1.size(); i++) c.push_back(a1[i]);
    for(ll i = max(0ll, (ll)b1.size() - m); i < (ll)b1.size(); i++) c.push_back(b1[i]);
    for(auto x : both) c.push_back(x);


    sort(c.begin(), c.end(), [&](ll a, ll b) {
        return a > b;
    });
    
    ll ct = min((ll)c.size(), n + m - 1);
    ll ans = 0;
    for(ll i = 0; i < ct; i++) ans += c[i];
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}
