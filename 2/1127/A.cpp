#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
我一开始想的是顺推 然后判断最后那个式子长什么样
但你会发现第一次操作是不知道的
但是这个操作可逆 直接逆推就行

*/


void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll p = 0;
    for(int i = n - 1; i >= 0; i--) p = 2 * a[i] - p;
    p = p / 2;
    cout << p << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}