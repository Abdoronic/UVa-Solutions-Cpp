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

double polyarea(vector< pair<double, double> > v) {
	double area = 0;
	for(int i = 0; i < sz(v) - 1; ++i)
		area += v[i].first * v[i+1].second - v[i].second * v[i+1].first;
	return abs(area) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(true) {
		cin >> n;
		if(n == 0) break;
		double vol = 0, T, x, y;
		string line;
		while(n--) {
			cin >> T;
			vector< pair<double, double> > poly;
			getline(cin, line);
			istringstream ss(line);
			while(ss >> x >> y)
				poly.pb({x, y});
			double area = polyarea(poly);
			vol += T * area;
		}
		cin >> x >> T;
		double manholeVol = M_PI * x * x * T;
		cout << floor(vol / manholeVol) << '\n';
	}
	return 0;
}
