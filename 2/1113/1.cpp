#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '0') { 
            s.erase(i, 1);
            break;
        }
    }
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '1') { 
            s.erase(i, 1);
            break;
        }
    }
    cout << s << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}