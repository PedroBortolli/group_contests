#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[1005], rev[1005], s[1005];
int seen[1005], top[1005], k = 0, sze[1005], color[1005], dp[1005], ch[1005];

void process(int x) {
	seen[x] = 1;
	for (auto a : v[x]) {
		if (!seen[a])
			process(a);
	}
	top[k++] = x;
}

void dfs(int x, int c) {
	color[x] = c;
	sze[c]++;
	s[c].pb(x);
	seen[x] = 1;
	for (auto a : rev[x]) {
		if (!seen[a]) {
			dfs(a, c);
		}
	}
}

int go(int x) {
	if (dp[x] != -1) return dp[x];
	int ans = 0;
	for (auto a : v[x]) {
		if (color[a] != color[x] && !seen[a]) {
			int aux = go(a);
			if (aux > ans) {
				ans = aux;
				ch[x] = a;
			}
		}
	}
	return dp[x] = ans + sze[color[x]];
}

int main() {
	int n, kk, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &kk);
		while (kk--) {
			scanf("%d", &x);
			v[i].pb(x);
			rev[x].pb(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (!seen[i]) {
			process(i);
		}
	}

	int c = 1;
	memset(seen, 0, sizeof(seen));
	for (int i = k-1; i >= 0; i--) {
		if (!color[top[i]]) {
			dfs(top[i], c);
			c++;
		}
	}

	memset(seen, 0, sizeof(seen));
	int rem = n, anss = 0;
	while (rem) {
		memset(dp, -1, sizeof(dp));
		memset(ch, -1, sizeof(ch));
		for (int i = 0; i < n; i++) {
			if (!seen[i]) go(i);
		}
		int mx = 0, p = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] > mx) {
				mx = dp[i];
				p = i;
			}
		}
		while (p != -1) {
			for (auto a : s[color[p]]) {
				rem--;
				seen[a] = 1;
			}
			p = ch[p];
		}
		anss++;
	}

	printf("%d\n", anss);
	return 0;
}