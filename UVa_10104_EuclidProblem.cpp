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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, x, y, d;
	while (cin >> a >> b) {
		d = egcd(a, b, x, y);
		printf("%d %d %d\n", x, y, d);
	}
	return 0;
}
