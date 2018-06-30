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

int TC, N, M, K;
int arr[1000005];
int vis[105];

inline bool full() {
	for(int i = 1; i <= K; i++)
		if(vis[i] == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> TC;
	for(int t = 1; TC--; t++) {
		cin >> N >> M >> K;
		memset(vis, 0, sizeof(vis));
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		for(int i = 3; i < N; i++)
			arr[i] = (arr[i-1] + arr[i-2] + arr[i-3])%M +1;
		int i = 0, j = 0, ans = INF;
		vis[1]++;
		while(i < N && j < N) {
			if(i > j)
				j = i;
			if(full()) {
				ans = min(ans, j - i + 1);
				if(arr[i] <= K)
					vis[arr[i]]--;
				i++;
			} else {
				j++;
				if(arr[j] <= K)
					vis[arr[j]]++;
			}
		}
		if(ans == INF)
			printf("Case %d: sequence nai\n", t);
		else
			printf("Case %d: %d\n", t, ans);

	}
	return 0;
}
