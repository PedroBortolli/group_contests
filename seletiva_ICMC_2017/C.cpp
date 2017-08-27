#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef pair <string, char> lol;
set <pair <pii, string> > st;
set <pair <lol, string> > inp[333];
set <pair <pii, string> >::iterator it;
string s, ver;
map <string, int> cont, pen;
map <pair <string, char>, int > fail;
int main() {
	std::ios::sync_with_stdio(false);
	int n, m, p, x, ans = 0;
	char prob;
	string team;
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (i == 0) team = s;
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> prob >> x >> ver;
		inp[x].insert(mp(mp(s, prob), ver));
	}

	for (int i = 0; i < 300; i++) {
		for (auto a : inp[i]) {
			string temp = a.first.first;
			prob = a.first.second;
			ver = a.second;
			if (ver != "OK") {
				fail[mp(temp,prob)]++;
				continue;
			}
			
			cont[temp]++;
			pen[temp] += (i + fail[mp(temp,prob)]*20);
			int solved = cont[temp];
			int penalty = pen[temp];
			//cout << temp << "  com  penalty de  " << penalty << "    e   solved   " << solved << endl;
			string add = "";
			if (temp == team) {
				add += "0";
			}
			add += temp;
			st.insert(mp(mp(-solved, penalty), add));
		}

		if (st.empty()) {
			ans++;
			continue;
		}
		it = st.begin();
		string tempp = it->second;

		string first = "";
		int len = tempp.size();
		int start = 0;
		if (tempp[0] == '0') start++;
		for (int i = start; i < len; i++) {
			first += tempp[i];
		}
		
		if (first == team) ans++;
	}

	printf("%d\n", ans);
	return 0;
}