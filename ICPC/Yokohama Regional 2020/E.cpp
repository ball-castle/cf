#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld pi = acosl(-1.0L);

double a[2010];

ll n;



bool check(double R) {
	double sum = 0;
	for(ll i = 1; i <= n; i++) {
		sum += asin(a[i] / 2 / R);
	}
	if(sum <= pi) return 0;
	else return 1;
}
bool check1(double R) {
	double sum = 0;
	for(ll i = 1; i <= n - 1; i++) {
		sum += asin(a[i] / 2 / R);
	}
	if(sum <= asin(a[n] / 2 / R)) return 1;
	else return 0;
}

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	

	ll f = 0;
	
	ld sum = 0;
	for(ll i = 1; i <= n; i++) {
		ld R = a[n] / 2;
		sum += asin(a[i] / 2 / R);
	}
	if(sum < pi) f = 1;


	double ans1, ans2;

	double l = a[n] / 2; 
	double r = 1000000;
	for(int i = 1; i <= 2000; i++) {
		double mid = (l + r) / 2;
		ans2 = mid;
		if(check1(mid)) l = mid;
		else r = mid;
		ans2 = mid;
	}
	
	
	
	l = a[n] / 2; 
	r = 1000000;
	for(int i = 1; i <= 20000; i++) {
		double mid = (l + r) / 2;
		ans1 = mid;
		if(check(mid)) l = mid;
		else r = mid;
		ans1 = mid;
	}
	
	if(f) printf("%.8lf\n", ans2);
	else printf("%.8lf\n", ans1);

	
	
}
