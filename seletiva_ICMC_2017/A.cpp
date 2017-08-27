#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, x, y;
	scanf("%d %d", &n, &x);
	if (n == 1) {
		scanf("%d", &y);
		if (y == x) printf("1\n");
		else printf("-1\n");
		return 0;
	}
	int ok = 0, hi = 0, lo = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &y);
		if (y == x) ok = 1;
		else if (y > x) hi = 1;
		else lo = 1;
	}
	if (ok) printf("1\n");
	else if (hi && lo) printf("2\n");
	else printf("-1\n");
	return 0;
}