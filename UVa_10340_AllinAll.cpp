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
	string s, t;
	while(cin >> s >> t) {
		int i = 0, j = 0;
		while(i < s.length() && j < t.length()) {
			if(s[i] == t[j]){
				i++; j++;
			} else {
				j++;
			}
		}
		cout << (i == s.length()? "Yes" : "No") << '\n';
	}
	return 0;
}
