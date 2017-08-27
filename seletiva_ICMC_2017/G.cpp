#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[33][33], dp[10005][29], k;

int go(int id, int prev) {
	if (id == k) return 0;
	if (dp[id][prev] != -1) return dp[id][prev];
	int ans = INT_MAX;
	for (int i = 1; i <= 26; i++) {
		ans = min(ans, v[prev][i]+go(id+1, i));
	}
	return dp[id][prev] = ans;
}

int main() {
	scanf("%d", &k);
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= 26; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));

	return 0;
}