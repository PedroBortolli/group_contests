#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char v[1000005];
int main() {
	ll n;
	scanf("%lld", &n);
	ll sum = (n*(n+1))/2;
	ll goal = sum/2;
	ll p = 0, s = 0;
	for (ll i = n; i >= 1; i--) {
		if (p+i <= goal) {
			v[i-1] = '+';
			p += i;
		}
		else {
			v[i-1] = '-';
			s += i;
		}
	}
	if (p != s) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		printf("%c", v[i]);
	printf("\n");
	return 0;
}