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
#define dbc(x) // cerr << x << '\n'
#define dbn(x) // cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

vector<string> split(string s, string del) {
	char *cs = (char *) malloc(s.size() + 10);
	strcpy(cs, s.c_str());
	vector<string> ret;
	for (char *p = strtok(cs, del.c_str()); p; p = strtok(NULL, del.c_str()))
		ret.pb(string(p));
	return ret;
}

const int MAXN = 412;
int aux = 0;

vector<int> start;
vector<int> adj[MAXN];
map<string, int> id;
set<int> seen;

bool vis[MAXN];

void dfs(int v) {
	dbc("asdasd");
	seen.insert(v);

	for (auto i : adj[v]) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);

	int n; cin >> n;

	for (int i=0; i<n; i++) {
		string s; int k;
		cin >> s >> k;
		if (id.find(s) == id.end()) id[s] = aux++;

		vector<string> vs = split(s,":");
		if (*(--vs.end()) == "PROGRAM") {
			start.pb(id[s]);
		}

		for (int j=0; j<k; j++) {
			string t; cin >> t;
			if (id.find(t) == id.end()) id[t] = aux++;
			
			adj[id[t]].pb(id[s]);

			vector<string> vs = split(t,":");

			for (string s : vs) dbn(s);

			if (*(--vs.end()) == "PROGRAM") {
				start.pb(id[t]);
			}
		}
	}

	for (int i : start) {
		m(vis, false);
		vis[i] = true;
		dfs(i);
	}

	for (auto i : id) {
		dbn(i.first);
		dbn(i.second);
		dbc("");
	}

	cout << n-seen.size() << endl;
}