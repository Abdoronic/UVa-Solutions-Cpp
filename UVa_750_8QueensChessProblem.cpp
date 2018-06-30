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

int queen[8];
vector< vi > sets;

bool valid(int r, int c) {
	for(int i = 0; i < c; i++)
		if(queen[i] == r || abs(r - queen[i]) == abs(c - i))
			return false;
	return true;
}

void generateQueens(int c) {
	if(c == 8)
		sets.pb(vi(queen, queen + 8));
	for(int r = 0; r < 8; r++) {
		if(valid(r, c)) {
			queen[c] = r;
			generateQueens(c+1);
		}
	}
}

int main() {
	generateQueens(0);
	int t, r, c;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &r, &c);
		r--; c--;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		int count = 1;
		for(int i = 0; i < sets.size(); i++) {
			if(sets[i][c] == r) {
				printf("%2d      ", count++);
				for(int j = 0; j < 8; j++)
					printf("%d%c", sets[i][j]+1, j == 7? '\n' : ' ');
			}
		}
		if(t > 0)
			printf("\n");
	}
	return 0;
}
