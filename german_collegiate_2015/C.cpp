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

	double a; int n; cin >> a >> n;

	for (int i=0; i<n; i++) {
		int x,y; cin >> x >> y;
		P.pb(point(double(x), double(y)));
	}

	double suma = 0.0;

	for (int i=0; i<n; i++) {
		polygon triangle;
		triangle.pb(P[i]);
		triangle.pb(P[(i+1)%n]);
		triangle.pb(P[(i+2)%n]);

		dbn(abs(poly_area(triangle)));
		suma += abs(poly_area(triangle));
	}

	double root = sqrt(suma/(abs(poly_area(P))*(1.0-a)));

	cout << fixed << setprecision(20) << root << endl; 
}