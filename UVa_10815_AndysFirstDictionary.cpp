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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> dict;
    string line, word;
    while(cin >> line) {
        transform(all(line), line.begin(), ::tolower);
        for(char& c : line)
            if(!('a' <= c && c <= 'z'))
                c = ' ';
        stringstream ss(line);
        while(ss >> word)
            dict.insert(word);
    }
    for(string i : dict)
        cout << i << '\n';
    return 0;
}
