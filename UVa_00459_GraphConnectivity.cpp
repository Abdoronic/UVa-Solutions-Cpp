#include <bits/stdc++.h>

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

vector< vi > adj;
vector<bool> vis;

void dfs(int u) {
	vis[u] = true;
	for(int v : adj[u])
		if(!vis[v])
			dfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		n = s[0] - 'A' + 1;
		getline(cin, s);
		adj.assign(n, vi());
		vis.assign(n, false);
		while(getline(cin, s) && s.length() > 0) {
			adj[s[0] - 'A'].pb(s[1] - 'A');
			adj[s[1] - 'A'].pb(s[0] - 'A');
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			if(!vis[i]) {
				ans++;
				dfs(i);
			}
		cout << ans << '\n';
		if(t) cout << '\n';
	}
	return 0;
}
