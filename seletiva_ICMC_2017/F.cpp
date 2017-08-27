#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[100005];
int b[100005], dp[100005][30];

void dfs(int x, int p) {
	dp[x][p] = b[x];
	for (auto a : v[x]) {
		dfs(a, p+1);
		for (int i = p+1; i < 30; i++) {
			dp[x][i] += dp[a][i];
		}
	}
}

int main() {
	int n, m, x, y, z;
	scanf("%d %d %d", &n, &m, &b[1]);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[y].pb(x);
		b[x] = z;
	}

	dfs(1, 0);

	while (m--) {
		int ans = 0;
		scanf("%d", &x);
		for (int i = 0; i < 30; i++) {
			ans = max(ans, dp[1][i]-dp[x][i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}