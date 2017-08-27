#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[222], mp[222], k = 0;
int main() {
	ll n, div = 0;	

	scanf("%lld", &n);
	for (ll i = 1; i < 210; i++) {
		if (i%2 and i%3 and i%5 and i%7) v[k++] = i;
	}
	while (n%2 == 0) {
		n /= 2;
		mp[2]++;	
	}
	while (n%3 == 0) {
		n /= 3;
		mp[3]++;
	}
	while (n%5 == 0) {
		n /= 5;
		mp[5]++;
	}
	while (n%7 == 0) {
		n /= 7;
		mp[7]++;
	}

	for (int j = 0; j < k; j++) {
		for (ll i = v[j]; i*i <= n; i += 210) {
			if (n%i == 0) {
				if (n/i == i) div++;
				else div += 2;
			}
		}
	}

	printf("%lld\n", div*(mp[2]+1)*(mp[3]+1)*(mp[5]+1)*(mp[7]+1));

	return 0;
}