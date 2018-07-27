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

int egcd(int a, int b, int& x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - a / b * y1;
	return d;
}

void findAnySolution(int a, int b, int c, int& x, int& y) {
	int g = egcd(a, b, x, y);
	x *= (c / g);
	y *= (c / g);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, x, k;
	cin >> tc;
	while(tc--) {
		cin >> x >> k;
		int a = floor(1.0 * x / k), b = ceil(1.0 * x / k);
		int p, q;
		findAnySolution(a, b, x, p, q);
		printf("%d %d\n", p, q);
	}
	return 0;
}
