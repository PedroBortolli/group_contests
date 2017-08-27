#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, x, prev = -1, ok = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x < prev) {
			ok = 0;
		}
		prev = x;
	}

	if (ok) printf("yes\n");
	else printf("no\n");
	return 0;
}	