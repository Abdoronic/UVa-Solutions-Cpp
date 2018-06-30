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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	int dragon[20005];
	int hero[20005];
	while (true) {
		cin >> n >> m;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> dragon[i];
		for (int i = 0; i < m; i++)
			cin >> hero[i];
		sort(dragon, dragon + n);
		sort(hero, hero + m);
		int sum = 0, i = 0, j = 0;
		while (i < n && j < m) {
			if (dragon[i] <= hero[j]) {
				sum += hero[j];
				i++;
				j++;
			} else {
				j++;
			}
		}
		if (i == n)
			cout << sum << '\n';
		else
			cout << "Loowater is doomed!\n";
	}
	return 0;
}
