#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();

    ll x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll s = ask(1, n);

    ll ans;

    if(s == 1) {
        ll l = s + 1, r = n;

        while(l < r) {
            ll mid = (l + r) >> 1;

            if(ask(s, mid) == s) r = mid;
            else l = mid + 1;
        }

        ans = l;
    }
    else if(s == n) {
        ll l = 1, r = s - 1;

        while(l < r) {
            ll mid = (l + r + 1) >> 1;

            if(ask(mid, s) == s) l = mid;
            else r = mid - 1;
        }

        ans = l;
    }
    else {
        if(ask(1, s) == s) {
            ll l = 1, r = s - 1;

            while(l < r) {
                ll mid = (l + r + 1) >> 1;

                if(ask(mid, s) == s) l = mid;
                else r = mid - 1;
            }

            ans = l;
        }
        else {
            ll l = s + 1, r = n;

            while(l < r) {
                ll mid = (l + r) >> 1;

                if(ask(s, mid) == s) r = mid;
                else l = mid + 1;
            }

            ans = l;
        }
    }

    cout << "! " << ans << endl;
    cout.flush();

    return 0;
}