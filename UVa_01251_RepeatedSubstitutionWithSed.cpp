#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back

#define INF int(1e9)
#define EPS 1e-9
#define MOD int(1e9 + 7)

int N;
string rep;
pair<string, string> arr[15];

string replaceAll(string s, string org, string rep) {
	size_t c = 0;
	while(s.find(org, c) != string::npos) {
		c = s.find(org, c);
		s.replace(c, org.length(), rep);
		c += rep.size();
	}
	return s;
}

int solve(string s) {
	if(s.length() > rep.length())
		return INF;
	if(s == rep) return 0;
	int ans = INF;
	for(int i = 0; i < N; i++) {
		if(s.find(arr[i].first) != string::npos) {
			ans = min(ans, 1 + solve(replaceAll(s, arr[i].first, arr[i].second)));
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string org, s1, s2;
	while(true) {
		cin >> N;
		if(N == 0) break;
		for(int i = 0; i < N; i++) {
			cin >> s1 >> s2;
			arr[i] = {s1, s2};
		}
		cin >> org >> rep;
		int ans = solve(org);
		cout << (ans >= INF? -1 : ans) << '\n';
	}
	return 0;
}
