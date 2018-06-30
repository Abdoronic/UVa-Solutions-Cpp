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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		int arr[n][m];
		bool adj[n][n];
		memset(adj, false, sizeof(adj));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		bool flag = true;
		for(int j = 0; j < m && flag; j++) {
			int u = -1, v = -1;
			for(int i = 0; i < n && flag; i++) {
				if(arr[i][j] == 1) {
					if(u == -1)
						u = i;
					else if(v == -1)
						v = i;
					else
						flag = false;
				}
			}
			if(adj[u][v] || v == -1)
				flag = false;
			else
				adj[u][v] = adj[v][u] = true;
		}
		cout << (flag? "Yes" : "No") << '\n';
	}
	return 0;
}
