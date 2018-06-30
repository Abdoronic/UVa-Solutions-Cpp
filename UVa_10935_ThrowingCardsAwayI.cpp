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
    int n;
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
        deque<int> d;
        vi v;
        for(int i = 1; i <= n; i++)
            d.push_back(i);
        while(d.size() > 1) {
            v.push_back(d.front());
            d.pop_front();
            int f = d.front();
            d.pop_front();
            d.push_back(f);
        }
        printf("Discarded cards:");
        for(int i = 0; i < v.size(); i++)
            printf("%s%d%s", i == 0? " " : "" ,v[i], i == v.size() - 1? "" : ", ");
        printf("\n");
        printf("Remaining card: %d\n", d.front());
    }
    return 0;
}