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

bool vis[105];
vector<vi> adj;

void dfs(int u) {
	for (int v : adj[u]) {
		if (!vis[v]) {
			vis[v] = true;
			dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q, u, v;
	string line;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		adj.assign(n, vi());
		getline(cin, line);
		while (getline(cin, line)) {
			istringstream ss(line);
			ss >> u;
			if (u == 0)
				break;
			while (ss >> v) {
				if (v == 0)
					break;
				adj[u - 1].pb(v - 1);
			}
		}
		cin >> q;
		while (q--) {
			cin >> u;
			memset(vis, false, sizeof vis);
			dfs(u - 1);
			int count = 0;
			for (int i = 0; i < n; i++)
				if (!vis[i])
					count++;
			cout << count;
			for (int i = 0; i < n; i++)
				if (!vis[i])
					cout << " " <<i + 1;
			cout << '\n';
		}
	}
	return 0;
}
