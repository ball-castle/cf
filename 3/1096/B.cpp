#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2227
*/
void solve() {
    ll n;
    cin >> n;
    
    string s;
    cin >> s;
    ll sum = 0;
    for(ll i = 0; i < (ll)s.size(); i++) {
        if(s[i] == '(') sum -= 1;
        if(s[i] == ')') sum += 1; 
    }
    cout << (sum == 0 ? "YES" : "NO") << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}