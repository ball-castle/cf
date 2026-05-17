#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    s += s;
    int cur = 0, maxc = 0;
    for(char &c : s) {
        if(c == '1') cur = 0;
        else {
            cur++;
            maxc = max(cur, maxc);
        }
    }

    cout << maxc << endl;
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}