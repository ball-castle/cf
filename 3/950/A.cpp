#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ct[10010];


void solve() {
    ll n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < 7; i++) ct[i] = 0;
    for(int i = 0; i < n; i++) ct[s[i] - 'A']++;
    for(int i = 0; i < 7; i++) ct[i] = min(ct[i], m), sum += ct[i];
    cout << m * 7 - sum << '\n';
    
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}