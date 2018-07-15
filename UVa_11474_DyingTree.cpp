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

int n, m, k, d, b, x, y;
vii tree[101];
ii doctor[11];

inline bool near(const ii& a, const ii& b, bool treeToTree) {
	if(treeToTree)
		return hypot(a.first - b.first, a.second - b.second) - k < EPS;
	else
		return hypot(a.first - b.first, a.second - b.second) - d < EPS;

}

inline bool connection(const vii& a, const vii& b) {
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++)
			if(near(a[i], b[j], true))
				return true;
	return false;
}

struct DSU {
	int n;
	int* p;
	int* rank;

	DSU (int n) {
		this->n = n;
		this->p = new int[n];
		this->rank = new int[n];
		for(int i = 0; i < n; i++) {
			p[i] = i;
			rank[i] = 0;
		}
	}

	int findSet(int i) { return i == p[i] ? i : p[i] = findSet(p[i]); }

	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

	void merge(int i, int j) {
		i = findSet(i);
		j = findSet(j);
		if(i == j) return;
		if(rank[i] < rank[j]) {
			p[i] = j;
		} else {
			p[j] = i;
			if(rank[i] == rank[j])
				rank[i]++;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> n >> m >> k >> d;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			doctor[i] = {x, y};
		}
		for(int i = 0; i < n; i++) {
			cin >> b;
			tree[i] = vii(b);
			for(int j = 0; j < b; j++) {
				cin >> x >> y;
				tree[i][j] = {x, y};
			}
		}
		DSU dsu(n);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(connection(tree[i], tree[j]))
					dsu.merge(i, j);
		bool survive = false;
		for(int i = 0; i < m && !survive; i++)
			for(int j = 0; j < n && !survive; j++)
				for(int k = 0; k < tree[j].size() && !survive; k++)
					if(near(doctor[i], tree[j][k], false) && dsu.isSameSet(0, j))
						survive = true;
		printf("%s\n", survive? "Tree can be saved :)" : "Tree can't be saved :(");
	}
	return 0;
}
