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
	int tc, d, n;
	int arr[1025][1025];
	cin >> tc;
	while(tc--) {
		cin >> d >> n;
		memset(arr, 0, sizeof(arr));
		int x,y, pop;
		for(int k = 0; k < n; k++) {
			cin >> x >> y >> pop;
			for(int i = max(0, x-d); i <= min(1024, x+d); i++)
				for(int j = max(0, y-d); j <= min(1024, y+d); j++)
					arr[i][j] += pop;
		}
		int max = 0;
		for(int i = 0; i < 1025; i++) {
			for(int j = 0; j < 1025; j++) {
				if(arr[i][j] > max) {
					max = arr[i][j];
					x = i;
					y = j;
				}
			}
		}
		cout << x << ' ' << y << ' ' << max << '\n';
	}
	return 0;
}
