#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

struct point {
    ll x, y;
    point(ll xp = 0, ll yp = 0) {
        x = xp;
        y = yp;
    }
    point(const point &p) {
        x = p.x;
        y = p.y;
    }
    point operator+ (const point &p) const {return point(x+p.x, y+p.y);}
    point operator- (const point &p) const {return point(x-p.x, y-p.y);}
    point operator* (ll c) {return point(c*x, c*y);}
    point operator/ (ll c) {return point(x/c, y/c);}

    bool operator<(const point &p) {return x < p.x || x == p.x && y < p.y;}
};

ll cross(point p, point q) {return p.x*q.y-p.y*q.x;}

vector<point> convex_hull(vector<point> p) {
    ll n = p.size(), k = 0;
    if (n == 1) return p;
    vector<point> hull(2*n);

    sort(p.begin(), p.end());

    for(ll i=0; i<n; i++) {
        while(k>=2 && (cross(hull[k-2], hull[k-1]) + cross(hull[k-1], p[i]) + cross(p[i], hull[k-2]) < 0)) k--;
        hull[k++] = p[i];
    }

    for(ll i=n-2,t=k+1; i>=0; i--) {
        while(k>=t && (cross(hull[k-2], hull[k-1]) + cross(hull[k-1], p[i]) + cross(p[i], hull[k-2]) < 0)) k--;
        hull[k++] = p[i];
    }

    hull.resize(k-1);
    return hull;
}

map <pll, ll> mp;
set <ll> xa, ya, xb, yb;
int main() {
	ll n, m, X, Y;
	scanf("%lld %lld", &n, &m);
	vector <point> h;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &X, &Y);
		mp[mp(X,Y)] = 1;
		h.pb(point(X,Y));
		xa.insert(X);
		ya.insert(Y);
	}

	for (int i = 0; i < m; i++) {
		scanf("%lld %lld", &X, &Y);
		if (mp[mp(X,Y)]) {
			printf("NO\n");
			return 0;
		}
		mp[mp(X,Y)] = 2;
		h.pb(point(X,Y));
		xb.insert(X);
		yb.insert(Y);
	}

	h = convex_hull(h);
	n = h.size();
	ll u = -1;
	for (int i = 0; i < n; i++) {
		X = h[i].x;
		Y = h[i].y;
		//printf("%lld %lld\n", X, Y);
		if (u == -1) u = mp[mp(X,Y)];
		else if (u != mp[mp(X,Y)]) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}