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
	int m, n;
	cin >> m >> n;
	map<string, int> dict;
	string key;
	int val;
	while(m--) {
		cin >> key >> val;
		dict.insert({key, val});
	}
	while(n--) {
		ll sum = 0;
		string word;
		while(true) {
			cin >> word;
			if(word == ".")
				break;
			if(dict.find(word) != dict.end())
				sum += dict[word];
		}
		cout << sum << '\n';
	}
	return 0;
}
