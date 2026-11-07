#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    vector<int> ct(26);

    for(auto &t : s) {
        cin >> t;
        for(char c : t) {
            ct[c - 'a']++;
        }
    }

    vector<int> id(26);
    for(int i = 0; i < 26; i++) {
        id[i] = i;
    }

    sort(id.begin(), id.end(), [&](int a, int b) {
        return ct[a] > ct[b];
    });

    vector<bool> keep(26);
    for(int i = 0; i < k; i++) {
        keep[id[i]] = 1;
    }
    char r = 'a' + id[0];
    for(auto &t : s) {
        for(char &c : t) {
            if(!keep[c - 'a']) c = r;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << s[i] << ' ';
    }
    cout << '\n';

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}