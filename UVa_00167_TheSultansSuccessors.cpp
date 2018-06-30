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

int n = 8;
int queen[8];
vector<vi> sets;

bool suitable(int r, int c) {
	for (int i = 0; i < c; i++) {
		if (queen[i] == r || abs(r - queen[i]) == abs(c - i))
			return false;
	}
	return true;
}

void generateQueens(int c) {
	if (c == n) {
		sets.pb(vi(queen, queen + n));
	}
	for (int r = 0; r < n; r++) {
		if (suitable(r, c)) {
			queen[c] = r;
			generateQueens(c + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	int arr[n][n];
	generateQueens(0);
	scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		int sum = 0, ans = 0;
		for (int i = 0; i < sets.size(); i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += arr[sets[i][j]][j];
			}
			ans = max(ans, sum);
		}
		printf("%5d\n", ans);
	}
	return 0;
}
