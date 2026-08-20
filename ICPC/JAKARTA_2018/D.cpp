    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    /*
    R行 C列

    */

    void solve() {
        ll r, c;
        cin >> r >> c;
        vector<string> s(r);
        for(ll i = 0; i < r; i++) cin >> s[i];

        ll f = 0; // 检查是否四周存在可以少一个的

        for(ll i = 1; i < c - 1; i++) {
            if(s[0][i] == '#') f = 1;
            if(s[r - 1][i] == '#') f = 1;
        }
        for(ll i = 1; i < r - 1; i++) {
            if(s[i][0] == '#') f = 1;
            if(s[i][c - 1] == '#') f = 1;
        }
        ll ans = 0;
        if(r <= 2 && c <= 2) {
            cout << 0 << '\n';
            return;
        }

        if(r == 1) {
            for(ll i = 1; i < c - 1; i++) {
                if(s[0][i] == '.') ans++;
            }
            cout << ans << '\n';
            return;
        }
        if(c == 1) {
            for(ll i = 1; i < r - 1; i++) {
                if(s[i][0] == '.') ans++; 
            }
            cout << ans << '\n';
            return;
        }
        if(r <= 2) {
            for(ll i = 1; i < c - 1; i++) {
                if(s[0][i] == '.' && s[1][i] == '.') ans++;
            }
            cout << ans << '\n';
            return;
        }
        if(c == 2) {
            for(ll i = 1; i < r - 1; i++) {
                if(s[i][0] == '.' && s[i][1] == '.') ans++;
            }
            cout << ans << '\n';
            return;
        }


        for(ll i = 1; i < r - 1; i++) {
            for(ll j = 1; j < c - 1; j++) {
                if(s[i][j] == '.') ans++;
            }
        }
        if(!f) ans++;
        cout << ans << '\n';
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        ll T = 1;
        while(T--) solve();
        return 0;
    }