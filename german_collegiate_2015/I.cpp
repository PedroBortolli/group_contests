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
#define inf 100000
using namespace std;

const double eps = 1e-9;
const double Pi = acos(-1.0);

inline int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) { return point(x * t, y * t); }
	point operator /(double t) { return point(x / t, y / t); }
	double operator *(point q) {return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
	double operator %(point q) {return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
	double polar() { return ((y > -eps) ? atan2(y,x) : 2*Pi + atan2(y,x)); }
	double mod() { return sqrt(x * x + y * y); }
	double mod2() { return (x * x + y * y); }
	point rotate(double t) {return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
	static point pivot;
};
point point::pivot;
typedef vector<point> polygon;


double poly_area(polygon& T) {
	double s = 0; int n = T.size();
	for (int i = 0; i < n; i++)
		s += T[i] % T[(i+1) % n];
	return s / 2;
}

polygon P;

int main() {
	ios::sync_with_stdio(false);
	long long w, s, x, y;
	cin >> w >> s >> x >> y;
	long long work[w][x], m[s][x], mt[x];
	for(long long j=0; j<x; j++) {
		mt[j]=inf;
	}
	for(long long i=0; i<w; i++) {
		for(long long j=0; j<x; j++) {
			cin >> work[i][j];
		}
	}
	for(long long i=0; i<s; i++) {
		for(long long j=0; j<x; j++) {
			cin >> m[i][j];
			m[i][j]=y-m[i][j];
		}
	}
	for(long long j=0; j<x; j++) {
		for(long long k=0; k<s; k++) {
			mt[j]=min(mt[j], m[k][j]);
		}
	}
	for(long long i=0; i<w; i++) {
		for(long long j=0; j<x; j++) {
			work[i][j]=min(work[i][j], mt[j]);
		}
	}
	for(long long i=0; i<w; i++) {
		for(long long j=0; j<x; j++) {
			printf("%lld ", work[i][j]);
		}
		printf("\n");
	}
}