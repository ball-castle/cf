#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2227/problem/B
*/


double a, b, l;

double d(double x) {
    double y = sqrt(l * l - x * x);
    return (a * y + b * x - x * y) / l;
}


void solve() {
    cin >> a >> b >> l;
    if(a > b) swap(a, b);
    if(l <= a) {printf("%.10f\n", l); return;}
    if(l <= b) {printf("%.10f\n", a); return;}

    double l1 = 0, r1 = l;
    for(int i = 0; i < 200; i++) {
        double m1 = l1 + (r1 - l1) / 3.0;
        double m2 = r1 - (r1 - l1) / 3.0;

        if(d(m1) < d(m2)) r1 = m2;
        else l1 = m1;
    }

    double ans = d((l1 + r1) / 2);
    
    if(ans < 1e-9) {printf("My poor head =(\n"); return;}
    printf("%.10f\n", ans);
}



int main() {
    int T;
    T = 1;
    while(T--) solve();
    return 0;
}