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

// fastscan made it x2 faster
int fastScan() {
	int num = 0;
	char c = getchar_unlocked();
	for(; c == ' ' || c == '\n'; c = getchar_unlocked());
	for(; c != ' ' && c != '\n'; c = getchar_unlocked())
		num = num * 10 + c - '0';
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, count;
	int arr[105];
	while(true) {
		cin >> n;
		if(n == 0) break;
		count = 0;
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < n; i++) {
			cin >> x;
			arr[x]++;
			count++;
		}
		for(int i = 0; i < 105; i++)
			while(arr[i]-- > 0) {
				count--;
				cout << i << (count? ' ' : '\n');
			}
	}
	return 0;
}
