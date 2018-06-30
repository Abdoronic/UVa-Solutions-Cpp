#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back

#define INF int(1e9)
#define EPS 1e-9
#define MOD int(1e9 + 7)

int main() {
    int N;
    char line[30];
    int arr[15][30];
    while(true) {
        scanf("%d%*c", &N);
        if(N == 0) break;
        int m = INF;
        for(int i = 0; i < N; i++) {
            scanf("%[^\n]%*c", line);
            int count = 0;
            for(int j = 0; j < 25; j++) {
                if(line[j] == 'X')
                    arr[i][j] = 1;
                else {
                    arr[i][j] = 0;
                    count++;
                }
            }
            m = min(m, count);
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            int count = 0;
            for(int j = 0; j < 25; j++) {
                if(arr[i][j] != 1)
                    count++;
            }
            ans += count - m;
        }
        printf("%d\n", ans);
    }
    return 0;
}

