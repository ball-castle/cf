n#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
转化为就是求b有多少个因子
学习一个sqrtl
根号求因子个数
*/

void solve() {
    ll cnt = 0;
    ll b;
    cin >> b;
    for(ll i = 1; i <= b / i; i++) {
        if(b % i == 0) {
            cnt += 2;
        }
    }
    ll r = sqrtl(b);
    if(r * r == b) {
        cnt--;
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}