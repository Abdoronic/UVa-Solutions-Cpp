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
	int TC, N, L;
	string line;
	int arr[15][15];
	cin >> TC;
	for(int t = 1; TC--; t++) {
		cin >> N;
		L = N+1;
		memset(arr, 'x', sizeof(arr));
		for(int i = 1; i < L; i++) {
			cin >> line;
			for(int j = 1; j < L; j++)
				arr[i][j] = line[j-1];
		}
		for(int i = 1; i < L; i++) {
			for(int j = 1; j < L; j++) {
				if(arr[i][j] != '.') continue;
				char c = 'A';
				while(c == arr[i][j-1] || c == arr[i][j+1] || c == arr[i-1][j] || c == arr[i+1][j])
					c++;
				arr[i][j] = c;
			}
		}
		cout << "Case " << t << ":\n";
		for(int i = 1; i < L; i++) {
			for(int j = 1; j < L; j++)
				cout << (char)arr[i][j];
			cout << '\n';
		}
	}
	return 0;
}
