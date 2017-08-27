#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, P, m, g, T;
int p[22], t[22], seen[20005];
map <pii, int> dist;
map <pii, int> c;
vector <int> v[100005];
int dp2[17][3][1 << 17];
int dp1[17][1 << 17];

int go1(int id, int est[]) {
	int aux = 0, d = 1, all = 1;
	for (int i = 0; i <= P; i++) {
		if (est[i] == 1) aux += d;
		else all = 0;
		d *= 2;
	}
	if (all) return t[id]+dist[mp(id,0)];
	if (dp1[id][aux] != -1) return dp1[id][aux];
	int ans = INT_MAX;
	for (int i = 0; i <= P; i++) {
		if (est[i] == 0) {
			est[i] = 1;
			ans = min(ans, t[id]+dist[mp(id,i)]+go1(i, est));
			est[i] = 0;
		}
	}
	return dp1[id][aux] = ans;
}

int go2(int id, int used, int est[]) {
	int aux = 0, d = 1, all = 1;
	for (int i = 0; i <= P; i++) {
		if (est[i] == 1) aux += d;
		else all = 0;
		d *= 2;
	}
	if (all) {
		if (used) return t[id]+dist[mp(id,0)];
		else return t[id]+min(dist[mp(id,0)], T);
	}
	if (dp2[id][used][aux] != -1) return dp2[id][used][aux];
	int ans = INT_MAX;
	for (int i = 0; i <= P; i++) {
		if (est[i] == 0) {
			est[i] = 1;
			ans = min(ans, t[id]+dist[mp(id,i)]+go2(i, used, est));
			if (!used) ans = min(ans, t[id]+T+go2(i, 1, est));
			est[i] = 0;
		}
	}
	printf("Id = %d    used = %d     =>     %d\n     ", id, used, ans);
	for (int i = 0; i <= P; i++) printf("%d ", est[i]);
	printf("\n\n");
	return dp2[id][used][aux] = ans;
}

int main() {
	int x, y, z, front;
	scanf("%d %d %d %d %d", &n, &P, &m, &g, &T);
	for (int i = 1; i <= P; i++) {
		scanf("%d %d", &p[i], &t[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].pb(y);
		v[y].pb(x);
		c[mp(x,y)] = z;
		c[mp(y,x)] = z;
	}

	for (int i = 0; i <= P; i++) {
		memset(seen, 0, sizeof(seen));
		front = i;
		set <pii> s;
		s.insert(mp(0, p[i]));
		while (!s.empty()) {
			pii pair = *s.begin();
			int dst = pair.first;
			int f = pair.second;
			if (!seen[f]) {
				dist[mp(front,f)] = dst;
				seen[f] = 1;
				for (auto a : v[f]) {
					if (!seen[a]) {
						int to = dst+c[mp(f,a)];
						s.insert(mp(to, a));
					}
				}
			}
			s.erase(pair);
		}
	}

	for (int i = 0; i <= P; i++) {
		for (int j = 0; j < n; j++) {
			printf("De   %d  ate %d      =>     %d\n", p[i], j, dist[mp(i,j)]);
		}
		printf("\n\n");
	}

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	int temp[22];
	memset(temp, 0, sizeof(temp));
	temp[0] = 1;
	int with = go1(0, temp);
	printf("%d\n", with);
	memset(temp, 0, sizeof(temp));
	temp[0] = 1;
	int without = go2(0, 0, temp);
	printf("%d\n", without);

	if (without <= g) printf("possible without taxi\n");
	else if (with <= g) printf("possible with taxi\n");
	else printf("impossible\n");
	return 0;
}