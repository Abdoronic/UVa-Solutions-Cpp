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
	double a, square, circ, diamond, tri, bell, cubix;
	while(cin >> a) {
		square = a * a;
		circ = M_PI * a * a / 4;
		diamond = 2 * circ - square;
		double areaSector = M_PI * a * a / 12.0;
		double x = 0.5 * a / tan(M_PI / 6);
		double areaTrap = 0.5 * (a + (a - x)) * a / 2;;
		tri = 2 * (areaTrap - areaSector);
		bell = circ - diamond - 2 * tri;
		cubix = diamond - 2 * bell;
		printf("%.3f %.3f %.3f\n", cubix, 4 * bell, 4 * tri);
	}
	return 0;
}
