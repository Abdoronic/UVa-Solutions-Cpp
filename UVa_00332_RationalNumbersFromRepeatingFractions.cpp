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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int k, j;
	string line;
	for(int t = 1; getline(cin, line); t++) {
		istringstream ss(line);
		ss >> j;
		if(j == -1) break;
		string word;
		ss >> word;
		word = word.substr(2, word.length() - 1);
		k = word.length() - j;
		ll num = stoll(word) - (k > 0 ? stoll(word.substr(0, k)) : 0);
		ll dem = (ll)pow(10, k + j) - (ll)pow(10, k);
		ll g = gcd(num, dem);
		if(g == 0) {
			num = stoll(word);
			dem = (ll)pow(10, word.length());
			g = gcd(num, dem);
		}
		num /= g;
		dem /= g;
		printf("Case %d: %lld/%lld\n", t, num, dem);
	}
	return 0;
}
