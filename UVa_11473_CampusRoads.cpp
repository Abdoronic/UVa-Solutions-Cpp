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
	double x, y;

	point() { x = y = 0; }

	point(double _x, double _y) : x(_x), y(_y) {}

	double dist(point p) { return hypot(p.x - x, p.y - y); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC, N, trees;
	point arr[105];
	cin >> TC;
	for(int t = 1; TC--; t++) {
		cin >> N >> trees;
		double x, y;
		for(int i = 0; i < N; i++) {
			cin >> x >> y;
			arr[i] = point(x, y);
		}
		double perimeter = 0;
		for(int i = 1; i < N; i++)
			perimeter += arr[i].dist(arr[i-1]);
		double fixed = perimeter / --trees;
		double remaining = fixed;
		vector<point> ans;
		ans.pb(arr[0]);
		point curr = arr[0];
		int next = 1;
		while(trees) {
			double d = curr.dist(arr[next]);
			if(remaining - d < EPS) {
				double dx, dy;
				if(abs(curr.x - arr[next].x) < EPS) {
					dx = 0;
					if(arr[next].y - curr.y < -EPS)
						dy = -remaining;
					else
						dy = remaining;
				} else {
					double theta = atan2((arr[next].y - curr.y) , (arr[next].x - curr.x));
					dx = remaining * cos(theta);
					dy = remaining * sin(theta);
				}
				curr = point(curr.x + dx, curr.y + dy);
				ans.pb(curr);
				remaining = fixed;
				trees--;
			} else {
				remaining -= d;
				curr = arr[next++];
			}
		}
		printf("Road #%d:\n", t);
		for(point i : ans)
			printf("%.2f %.2f\n", i.x, i.y);
		printf("\n");
	}
	return 0;
}
