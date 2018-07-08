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

int n;
int OFFSET = 3000;
int arr[31];
bool sign[31];
bool memo[31][31][6000];
set<int> sums;

void dp(int idx, int open, int sum) {
	if(idx == n) {
		if(sums.find(sum) == sums.end())
			sums.insert(sum);
		return;
	}
	if(memo[idx][open][sum + OFFSET]) return;
	int val = sign[idx]? -arr[idx] : arr[idx];
	val = open % 2 == 0? val : -val;
	if(open > 0)
		dp(idx + 1, open - 1, sum + val);
	if(sign[idx])
		dp(idx + 1, open + 1, sum + val);
	dp(idx + 1, open, sum + val);
	memo[idx][open][sum + OFFSET] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	char sgn;
	sign[0] = false;
	while(getline(cin, line)) {
		istringstream ss(line);
		ss >> arr[0];
		for(n = 1; ss >> sgn; n++) {
			sign[n] = sgn == '-';
			ss >> arr[n];
		}
		memset(memo, false, sizeof memo);
		sums.clear();
		dp(0, 0, 0);
		cout << sums.size() << '\n';
	}
	return 0;
}
