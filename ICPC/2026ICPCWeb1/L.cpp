#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int tr[500005][26];   // 当前在第i个节点 要走到j这个字符 要走到下一个点是哪一个点
int cnt[500005], dep[500005], best[500005];

/*
cnt 这个前缀被多少字符拥有
dep 这个前缀有多长
用u这个节点就代表从一开始到这个位置的一个前缀


*/

int tot;

void solve() {
    int n;
    cin >> n;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int u = 0;
        ans += i;
        for(char ch : s) {
            int c = ch - 'a';

            if(!tr[u][c]) {
                tr[u][c] = ++tot;
                dep[tot] = dep[u] + 1;
            } 
            u = tr[u][c];
            ++cnt[u];

            int j = cnt[u];
            if(dep[u] > best[j]) {
                ans -= (best[j] ^ j);
                best[j] = dep[u];
                ans += (best[j] ^ j);
            }
        }
        cout << ans << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}