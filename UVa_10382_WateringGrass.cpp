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

bool compare(const pair<double, double>& x, const pair<double, double>& y) {
	if(abs(x.first - y.first) < EPS)
		return y.second - x.second < -EPS;
	return x.first - y.first < -EPS;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int G, L, W;
	while(cin >> G >> L >> W) {
		pair<double, double> arr[G];
		int N = 0, j = 0, x, r;
		for(int i = 0; i < G; i++) {
			cin >> x >> r;
			if(r < ceil(W/2.0)) continue;
			double dx = sqrt((double)r*r - W*W/4.0);
			arr[j++] = {x - dx, x + dx};
			N++;
		}
		sort(arr, arr + N, compare);
		int i = 0, count = 0;
		double last = 0.0;
		while(last - L < -EPS) {
			double mx = last;
			while(i < N && !(arr[i].first - last > EPS))
				mx = max(mx, arr[i++].second);
			if(abs(mx - last) < EPS)
				break;
			last = mx;
			count++;
		}
		if(last - L < -EPS)
			cout << -1 << '\n';
		else
			cout << count << '\n';
	}
	return 0;
}
