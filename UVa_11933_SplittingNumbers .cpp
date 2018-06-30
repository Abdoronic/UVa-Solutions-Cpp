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
    int n;
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        int a = 0, b = 0, bit;
        int p = 0;
        while(n) {
            bit = n&(-n);
            n -= bit;
            if(p == 0)
                a += bit;
            else
                b += bit;
            p = 1 - p;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}