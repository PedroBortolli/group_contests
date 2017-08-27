#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	double r, x, y;
	int ans = 0, pt = 10;
	scanf("%lf", &r);
	for (int i = 0; i < 3; i++) {
		pt = 10;
		scanf("%lf %lf", &x, &y);
		for (double z = r; z <= 10.0*r; z += r, pt--) {
			if (x*x + y*y <= z*z) {
				ans += pt;
				break;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
