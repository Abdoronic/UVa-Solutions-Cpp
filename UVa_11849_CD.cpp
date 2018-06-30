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
	int n, m;
	while(true) {
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;
		vi v1(n), v2(m);
		vi ans(n);
		for(int i = 0; i < n; i++)
			cin >> v1[i];
		for(int i = 0; i < m; i++)
			cin >> v2[i];
		auto ls = set_intersection(all(v1), all(v2), ans.begin());
		//ans.resize((size_t)(ls - ans.begin()));
		cout << ans.size() << '\n';
	}
	return 0;
}
