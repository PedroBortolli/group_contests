#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, ok = 0;

void check(char v[]) {
	int p = 0, l = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == '+') p += (i+1);
		else l += (i+1);
	}
	if (p == l) {
		for (int i = 0; i < n; i++)
			printf("%c", v[i]);
		printf("\n");
		ok = 1;
	}
}

void f(int id, char v[]) {
	if (ok) return;
	if (id == n) check(v);
	else {
		v[id] = '+';
		f(id+1, v);
		v[id] = '-';
		f(id+1, v);
	}
}

int main() {
	scanf("%d", &n);
	printf("%lld", n*n);
	return 0;
	char temp[22];
	f(0, temp);
	if (!ok) printf("-1\n");
	return 0;
}