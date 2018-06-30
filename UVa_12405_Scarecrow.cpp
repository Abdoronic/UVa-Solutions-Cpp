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

int main() {
	int t, n;
	char line[105];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		scanf("%s", line);
		int ans = 0;
		char pre = line[0];
		for (int j = 1; j < n; j++) {
			if (pre == '.') {
				line[j - 1] = '#';
				line[j] = '#';
				if (j + 1 < n)
					line[j + 1] = '#';
				ans++;
			}
			pre = line[j];
		}
		if (pre == '.')
			ans++;
		printf("Case %d: %d\n", i, ans);
	}
	return 0;
}
