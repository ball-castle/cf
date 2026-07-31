#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}