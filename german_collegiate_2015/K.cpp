#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) cerr << x << '\n'
#define dbn(x) //cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
int mp[20];

// ll po(ll x, ll e) {
// 	ll res = 1ll;
// 	for (int i=0; i<e; i++) {
// 		res *= x;
// 	}
// 	return res;
// }

ll po[20];

int digit(ll s, ll x) {
	return (s/po[x]) % 10;
}

int qtdigits(ll s) {
	if (s == 0) return 1;
	return floor(log10(s)) + 1;
}

bool isPrime(ll x) {
	if (x <= 1) return false;
	
	if (x == 2) return true;

	if (x % 2 == 0) return false;

	for (ll i=3; i*i<=x; i+=2) {
		if (x % i == 0) return false;
	}

	return true;
}

ll rotate(ll x) {
	ll res = 0;
	ll sz = qtdigits(x);

	for (ll i=0; i<sz; i++) {
		res *= 10;
		ll rev = mp[digit(x, i)];
		
		if (rev == -1) {
			printf("no\n");
			// cout << "no" << endl;
			exit(0);
		}

		res += rev; 
	}

	return res;
}

int main() {
	ll s; scanf("%lld", &s);

	if (!isPrime(s)) {
		printf("no\n");
		return 0;
	}

	po[0] = 1ll;
	for (ll i=1; i<20; i++) {
		po[i] = 10*po[i-1];
	}

	mp[0] = 0;
	mp[1] = 1;
	mp[2] = 2;
	mp[3] = -1;
	mp[4] = -1;
	mp[5] = 5;
	mp[6] = 9;
	mp[7] = -1;
	mp[8] = 8;
	mp[9] = 6;

	if (isPrime(rotate(s))) {
		printf("yes\n");
		// cout << "yes" << endl;
	} else {
		printf("no\n");
		// cout << "no" << endl;
	}
	return 0;
}