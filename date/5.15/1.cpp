#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    s = ' ' + s;

    while(m--) {
        ll l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for(int i = l; i <= r; i++) if(s[i] == c1) s[i] = c2;
    }
    s = s.substr(1);
    cout << s << '\n';
    return 0;
}