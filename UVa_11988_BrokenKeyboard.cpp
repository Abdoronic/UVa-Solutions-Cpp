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

deque<string> ans;

void handle(string acc, char ind) {
    if(ind == '[')
        ans.push_front(acc);
    else
        ans.push_back(acc);
}

int main() {
    char line[100005];
    while(fgets(line, sizeof(line), stdin) != NULL) {
        char ind = '[';
        string acc = "";
        for(int i = 0; true; i++) {
            char c = line[i];
            if(c == '[' || c == ']' || c == '\n') {
                handle(acc, ind);
                ind = c;
                acc = "";
                if(c == '\n') break;
            } else {
                acc += c;
            }
        }
        while(!ans.empty()) {
            printf("%s", ans.front().c_str());
            ans.pop_front();
        }
        printf("\n");
    }
    return 0;
}