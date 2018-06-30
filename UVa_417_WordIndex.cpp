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

inline string nextWord(string s) {
	for(int i = s.length()-1; i >= 0; i--) {
		char& c = s[i];
		c++;
		if(c > 'z' - (s.length()-1 - i)) {
			c = 'a';
			if(i == 0)
				s = "a" + s;
			continue;
		}
		break;
	}
	for(int i = 1; i < s.length(); i++)
		if(s[i] <= s[i-1])
			s[i] = s[i-1] + 1;
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	map<string, int> words;
	string acc = "a";
	int val = 1;
	words.insert({acc, val});
	while(acc.length() < 6) {
		acc = nextWord(acc);
		val++;
		words.insert({acc, val});
	}
	while(cin >> s) {
		if(words.find(s) != words.end())
			cout << words[s] << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
