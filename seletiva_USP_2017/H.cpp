#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <pair <char, int> > ans1, ans2;
char v[12] = {'N', 'E', 'S', 'O', 'N', 'E', 'S', 'O', 'N', 'E', 'S', 'O'};
int main() {
	int x, y, X, Y, dist, p = 0, prev;
	char c, d1, d2;
	scanf("%d %d %c", &x, &y, &c);
	scanf("%d %d", &X, &Y);

	if (X > x) d1 = 'E';
	else if (X < x) d1 = 'O';
	else d1 = '!';

	if (Y > y) d2 = 'N';
	else if (Y < y) d2 = 'S';
	else d2 = '!';

	prev = -1;
	if (d1 != '!') {
		for (p = 0; p < 12; p++) {
			if (v[p] == c) break;
		}
		prev = p;
		for (; p < 12; p++) {
			if (v[p] == d1) break;
			ans1.pb(mp('D', -1));
		}
		if (abs(X-x) != 0) ans1.pb(mp('A', abs(X-x)));
	}

	if (d2 != '!') {
		if (prev == -1) {
			for (p = 0; p < 12; p++) {
				if (v[p] == c) break;
			}
		}
		for (; p < 12; p++) {
			if (v[p] == d2) break;
			ans1.pb(mp('D', -1));
		}
		if (abs(Y-y) != 0) ans1.pb(mp('A', abs(Y-y)));
	}

	prev = -1;
	if (d2 != '!') {
		for (p = 0; p < 12; p++) {
			if (v[p] == c) break;
		}
		prev = p;
		for (; p < 12; p++) {
			if (v[p] == d2) break;
			ans2.pb(mp('D', -1));
		}
		if (abs(Y-y) != 0) ans2.pb(mp('A', abs(Y-y)));
	}

	if (d1 != '!') {
		if (prev == -1) {
			for (p = 0; p < 12; p++) {
				if (v[p] == c) break;
			}
		}
		for (; p < 12; p++) {
			if (v[p] == d1) break;
			ans2.pb(mp('D', -1));
		}
		if (abs(X-x) != 0) ans2.pb(mp('A', abs(X-x)));
	}

	if ((int)ans1.size() <= (int)ans2.size()) {
		printf("%d\n", (int)ans1.size());
		for (auto a : ans1) {
			printf("%c", a.first);
			if (a.second != -1) printf(" %d", a.second);
			printf("\n");
		}
		
	}

	else {
		printf("%d\n", (int)ans2.size());
		for (auto a : ans2) {
			printf("%c", a.first);
			if (a.second != -1) printf(" %d", a.second);
			printf("\n");
		}
	}

	return 0;
}