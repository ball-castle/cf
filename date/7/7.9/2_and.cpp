#include <bits/stdc++.h>
using namespace std;
using ll = long long;



/*
分块处理 和按位处理是位运算很重要的感觉

*/

void solve() {
    ll n;
    cin >> n;

    if(n % 2 == 1) {
        cout << "NO" << '\n';
    }
    else {
        vector<ll> p(n + 1);

        ll r = n;
        while(r > 0) {
            ll mask = 1;
            while(mask < r) {
                mask = mask * 2 + 1;
            }
            ll l = mask - r;
            for(ll i = l; i <= r; i++) {
                p[i] = mask ^ i;
            }

            r = l - 1;
        }
        cout << "YES" << '\n';
        for(ll i = 1; i <= n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    auto check = [&](ll n) -> ll {
        return (n & (n - 1)) == 0;
    };

    if(n < 6 || check(n)) {
        cout << "NO" << '\n';
    }
    else {
        vector<ll> q(n + 1);
        if(n == 6) {
            vector<ll> a = {1, 3, 2, 6, 4, 5};
            
            for(ll i = 0; i < (ll)a.size(); i++) {
                q[a[i]] = a[(i + 1) % a.size()];
            }
        }
        else {
            vector<ll> a = {1, 3, 2, 6, 4, 5, 7};

            for(ll i = 0; i < (ll)a.size(); i++) {
                q[a[i]] = a[(i + 1) % a.size()];
            }

            for(ll l = 8; l <= n; l <<= 1) {
                ll r = min(n, 2 * l - 1);

                for(ll i = l; i < r; i++) {
                    q[i] = i + 1;
                }
                q[r] = l;
            }
        }
        cout << "YES" << '\n';
        for(ll i = 1; i <= n; i++) cout << q[i] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    
    while(T--) {
        solve();
    }
    
    return 0;
}
