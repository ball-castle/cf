#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll d, L, v1, v2;
    cin >> d >> L >> v1 >> v2;

    double t = (double)(L - d) / (v1 + v2);

    printf("%10lf\n", t);

}




int main() {    
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);


    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}