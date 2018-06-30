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
	int N, M, num;
	while (cin >> N >> M) {
		vector<vi> vec(1000001, vi());
		for (int i = 1; i <= N; i++) {
			cin >> num;
			vec[num].pb(i);
		}
		int v, k, ans;
		while (M--) {
			cin >> k >> v;
			for (int j = 0; j < vec[v].size() && k--; j++) {
				ans = vec[v][j];
			}
			if (k > 0)
				cout << 0 << '\n';
			else
				cout << ans << '\n';
		}
	}
	return 0;
}
