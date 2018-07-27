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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, g, l;
	cin >> t;
	while(t--) {
		cin >> g >> l;
		if(l < g || l % g != 0)
			printf("-1\n");
		else
			printf("%d %d\n", g, l);
	}
	return 0;
}
