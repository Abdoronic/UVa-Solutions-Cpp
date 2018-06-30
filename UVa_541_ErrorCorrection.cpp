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

int n;
int arr[105][105];

ii rows() {
    ii p = {0, 0};
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        if(sum%2 != 0) {
            p.first++;
            p.second = i+1;
        }
    }
    return p;
}

ii cols() {
    ii p = {0, 0};
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            sum += arr[j][i];
        }
        if(sum%2 != 0) {
            p.first++;
            p.second = i+1;
        }
    }
    return p;
}

int main() {
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &arr[i][j]);
        ii c = cols();
        ii r = rows();
        if(c.first == 0 && r.first == 0)
            printf("OK\n");
        else if(c.first == 1 && r.first == 1)
            printf("Change bit (%d,%d)\n", r.second, c.second);
        else
            printf("Corrupt\n");

    }
    return 0;
}
