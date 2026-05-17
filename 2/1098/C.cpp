#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, n;
    cin >> a >> n;

    vector<ll> d(n);
    for(ll i = 0; i < n; i++) cin >> d[i];

    string s = to_string(a);
    ll len = s.size();
    ll ans = 4e18;

    for(auto x : d) ans = min(ans, abs(a - x));

    if(len >= 3) {
        ll f = -1;
        for(auto x : d) if(x != 0) f = x;

        if(f != -1) {
            ll b = f;
            for(ll i = 1; i < len - 1; i++) b = b * 10 + d.back();
            ans = min(ans, abs(a - b));
        }
    }

    ll f = -1;
    for(auto x : d) if(x != 0) {f = x; break;}

    if(f != -1) {
        ll b = f;
        for(ll i = 1; i < len + 1; i++) b = b * 10 + d[0];
        ans = min(ans, abs(a - b));
    }

    bool ok1 = true;
    for(ll i = 0; i < len && ok1; i++) {
        ll c = s[i] - '0';

        ll f = -1;
        for(auto x : d) {
            if(i == 0 && len > 1 && x == 0) continue;
            if(x < c) f = x;
        }

        if(f != -1) {
            ll b = 0;

            for(ll j = 0; j < i; j++) b = b * 10 + s[j] - '0';
            b = b * 10 + f;
            for(ll j = i + 1; j < len; j++) b = b * 10 + d.back();

            ans = min(ans, abs(a - b));
        }

        bool f1 = 0;
        for(auto x : d) {
            if(i == 0 && len > 1 && x == 0) continue;
            if(x == c) f1 = true;
        }

        if(!f1) ok1 = false;
    }

    if(ok1) ans = 0;

    bool ok2 = true;
    for(ll i = 0; i < len && ok2; i++) {
        ll c = s[i] - '0';

        ll f = -1;
        for(auto x : d) {
            if(i == 0 && len > 1 && x == 0) continue;
            if(x > c) {f = x; break;}
        }

        if(f != -1) {
            ll b = 0;

            for(ll j = 0; j < i; j++) b = b * 10 + s[j] - '0';
            b = b * 10 + f;
            for(ll j = i + 1; j < len; j++) b = b * 10 + d[0];

            ans = min(ans, abs(a - b));
        }

        bool f1 = false;
        for(auto x : d) {
            if(i == 0 && len > 1 && x == 0) continue;
            if(x == c) f1 = true;
        }

        if(!f1) ok2 = false;
    }
    if(ok2) ans = 0;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}