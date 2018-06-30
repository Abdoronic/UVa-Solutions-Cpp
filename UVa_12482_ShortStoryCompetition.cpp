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
	int N, L, C;
	string word;
	string arr[1005];
	while(cin >> N >> L >> C) {
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		int charCount = 0, lineCount = 1, pageCount = 1;
		int i = 0;
		while(i < N) {
			if(charCount + arr[i].length() > C) {
				charCount = 0;
				lineCount++;
				if(lineCount > L) {
					lineCount = 1;
					pageCount++;
				}
			}
			charCount += arr[i++].length() + 1;
			while(i < N && charCount + arr[i].length() <= C)
					charCount += arr[i++].length() + 1;
		}
		cout << pageCount << '\n';
	}
	return 0;
}
