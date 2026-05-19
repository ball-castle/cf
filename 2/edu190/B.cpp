#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2230/submit\
从结论出发
12
32
左边都是2，右边都是13
*/
void solve() {
    string s;
    cin >> s;
    vector<ll> ct(10);
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == '2') ct[2]++;
        if(s[i] == '4') ct[4]++;
    }
    ll mx = n - ct[2] - ct[4];
    ll cnt2 = 0, cnt13 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '2') cnt2++;
        if(s[i] == '1' || s[i] == '3') cnt13++;
        mx = max(mx, cnt2 + n - ct[2] - cnt13 - ct[4]);
    }
    cout << n - mx << '\n'; 


}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}