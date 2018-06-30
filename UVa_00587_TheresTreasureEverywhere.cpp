#include <bits/stdc++.h>

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

void eval(int n, string d, pair<double, double>& p) {
	double dig = cos((45*M_PI)/180)*n;
	double& x = p.first;
	double& y = p.second;
	if(d == "N") {
		y += n;
	} else if(d == "S") {
		y -= n;
	} else if(d == "W") {
		x -= n;
	} else if(d == "E") {
		x += n;
	} else if(d == "NW") {
		y += dig; x -= dig;
	} else if(d == "NE") {
		y += dig; x += dig;
	} else if(d == "SW") {
		y -= dig; x -= dig;
	} else if(d == "SE") {
		y -= dig; x += dig;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	for(int t = 1; getline(cin, line); t++) {
		if(line == "END") break;
		for(char& c : line)
			if(c == ',' || c == '.') c = ' ';
		istringstream ss(line);
		pair<double, double> p = {0, 0};
		while(ss >> line) {
			int num = 0;
			string d = "";
			for(char c : line) {
				if('0' <= c && c <= '9')
					num = num * 10 + c - '0';
				else
					d += c;
			}
			eval(num, d, p);
		}
		printf("Map #%d\n", t);
		printf("The treasure is located at (%.3f,%.3f).\n", p.first, p.second);
		printf("The distance to the treasure is %.3f.\n\n", hypot(p.first, p.second));
	}
	return 0;
}
