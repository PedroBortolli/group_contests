#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 3e5+5;
vector <pair <pii, pair <pii, int> > > s;
vector <int> sty;
map <int, int> mp;
int bit[N], ans[N];

void update(int i, int val) {
	while (i < N) {
		bit[i] += val;
		i += (i&-i);
	}
}

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

int main() {
	int n, m, x, y, X, Y, t;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		s.pb(mp(mp(x,2), mp(mp(y, 1), i)));
		sty.pb(y);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x, &y, &X, &Y);
		s.pb(mp(mp(X,1), mp(mp(Y, x), y)));
		s.pb(mp(mp(x,3), mp(mp(y, X), Y)));
		sty.pb(y);
		sty.pb(Y);
	}

	int cont = 0;

	sort(s.begin(), s.end());
	sort(sty.begin(), sty.end());

	for (auto a : sty)
		mp[a] = ++cont;

	for (auto a : s) {
		x = a.first.first;
		t = a.first.second;
		y = a.second.first.first;
		X = a.second.first.second;
		Y = a.second.second;

		if (t == 1) {
			update(min(mp[y], mp[Y])+1, -1);
			update(max(mp[y], mp[Y]), 1);
		}
		else if (t == 2) {
			ans[Y] = query(mp[y]);
		}
		else if (t == 3) {
			update(min(mp[y], mp[Y])+1, 1);
			update(max(mp[y], mp[Y]), -1);
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}