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

inline bool notAlpha(char c) {
	return !('a' <= c && c <= 'z');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	set<string> dict;
	string res;
	while (cin >> line) {
		transform(all(line), line.begin(), ::tolower);
		for (int i = 0; i < line.length(); i++) {
			char& c = line[i];
			if (i == line.length() - 1) {
				if (c == '-')
					line = line.substr(0, line.length()-1);
				else if (notAlpha(c))
					c = ' ';
				else
					line += ' ';
			} else {
				if (notAlpha(c) && c != '-')
					c = ' ';
			}
		}
		res += line;
	}
	istringstream ss(res);
	string word;
	while (ss >> word)
		dict.insert(word);
	for (string i : dict)
		cout << i << '\n';
	return 0;
}
