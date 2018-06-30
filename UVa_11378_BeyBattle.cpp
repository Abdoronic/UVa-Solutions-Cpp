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

struct point {
	int x, y;

	point() { x = y = 0; }

	point(int _x, int _y) : x(_x), y(_y) {}

	bool operator< (const point& p) const {
			return x < p.x;
	}
};

struct ord {
	bool operator()(const point& a, const point& b) const {
		return a.y < b.y;
	}
};

int dist(point a, point b) {
	return max(abs(a.x - b.x), abs(a.y - b.y));
}

int solve(point arr[], int n) {
	set<point, ord> events;
	int d = INF;
	for(int i = 0, j = 0; i < n; ++i) {
		while(j < i && arr[j].x > arr[i].x + d)
			events.erase(arr[j++]);
		auto start = events.lower_bound(point(arr[i].x, arr[i].y - d));
		for(; start != events.end() && start->y < arr[i].y + d; ++start)
			d = min(d, dist(arr[i], *start));
		events.insert(arr[i]);
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	point arr[100005];
	while(cin >> n) {
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			arr[i] = point(x, y);
		}
		sort(arr, arr + n);
		int closestDist = solve(arr, n);
		cout << closestDist << '\n';
	}
	return 0;
}
