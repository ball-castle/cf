#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2230/submit\
从结论出发
LR什么时候会计数
就是从某个合法点往后跳
对于每个LR它都默认什么都没有看过
所以只需要对于每个L枚举第一次出现的就行

*/

ll a[500010], b[500010];
ll f[500010];
vector<ll> E[500010];


void solve() {
    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) {
        E[a[i]].push_back(i);
        if(a[i] != b[i]) E[b[i]].push_back(i);
    }
    // f[i] 表示从第i天开始第一次出问题的日子
    f[n + 1] = n + 1;
    for(int i = n; i >= 1; i--) {
        if(a[i] != b[i]) f[i] = i;
        else {
            int x = a[i] + 1;
            auto it = upper_bound(E[x].begin(), E[x].end(), i);

            if(it == E[x].end()) f[i] = n + 1;
            else f[i] = f[*it];
        }
    }

    ll ans = 0;
    int r = n + 1;

    for(int l = n; l >= 1; l--) {
        if(a[l] == 1 || b[l] == 1) r = l;
        ans += f[r] - l;
    }

    cout << ans << '\n';

    for(int i = 1; i <= n + 1; i++) E[i].clear(); 
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}