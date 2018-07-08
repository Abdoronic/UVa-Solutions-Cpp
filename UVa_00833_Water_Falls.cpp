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

//Geometry Library
struct vec;
struct point;
struct line;
struct lineSegment;

struct vec {
	double x, y;

	vec(double _x, double _y) : x(_x), y(_y) {}

	bool operator== (const vec& v) { return abs(x - v.x) < EPS && abs(y - v.y) < EPS; }

	vec scale(double s) { return vec(x * s, y * s); }

	double dot(vec v) { return x * v.x + y * v.y; }

	double cross(vec v) { return x * v.y - y * v.x; }

	double norm2() { return x * x + y * y; }

	vec normalize() { return scale( 1 / sqrt(norm2()) ); }

	vec reverse() { return vec(-x, -y); }
};

struct point {
	double x, y;

	point() { x = y = 0; }

	point(double _x, double _y) : x(_x), y(_y) {}

	bool operator< (const point& p) const {
		if(abs(y - p.y) > EPS)
			return y < p.y;
		return x - p.x < -EPS;
	}

	bool operator== (const point& p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}

	static vec make_vec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

	double dist(point p) { return hypot(p.x - x, p.y - y); }

	point translate(vec v) { return point(x + v.x, y + v.y); }

	point rotate(double theta) {
		double c = cos(theta), s = sin(theta);
		return point(c*x - s*y, s*x + c*y);
	}

	point rotate(double theta, point about) {
		vec v = make_vec(about, point(0, 0));
		return translate(v).rotate(theta).translate(v.reverse());
	}

	bool between(point p, point q) {
		return x - max(p.x, q.x) < EPS && x - min(p.x, q.x) > -EPS
				&& y - max(p.y, q.y) < EPS && y - min(p.y, q.y) > -EPS;
	}

	bool onLine(point p, point q) {
		if(p == q) return (*this) == p;
		vec pq = make_vec(p, q), pr = make_vec(p, *this);
		return abs(pq.cross(pr)) < EPS;
	}

	bool onRay(point p, point q) {
		if(p == q) return (*this) == p;
		vec pq = make_vec(p, q), pr = make_vec(p, *this);
		return pq.normalize() == pr.normalize();
	}

	bool onSegment(point p, point q) {
		if(p == q) return (*this) == p;
		return onRay(p, q) && onRay(q, p);
	}

	static bool colinear(point p, point q, point r) {
		vec pq = make_vec(p, q), pr = make_vec(p, r);
		return abs(pq.cross(pr)) < EPS;
	}

	static bool cw(point p, point q, point r) {
		vec pq = make_vec(p, q), pr = make_vec(p, r);
		//if onLine points acceptable then { < EPS }
		return pq.cross(pr) < 0;
	}

	static bool ccw(point p, point q, point r) {
		vec pq = make_vec(p, q), pr = make_vec(p, r);
		//if onLine points acceptable then { > -EPS }
		return pq.cross(pr) > 0;
	}

	static double angle(point a, point o, point b) {
		vec oa = make_vec(o, a), ob = make_vec(o, b);
		return acos(oa.dot(ob)/sqrt(oa.norm2() * ob.norm2()));
	}

	point reflection(line l);

	double dist_to_line(point a, point b);

};

struct line {
	double a, b, c;

	line(){ a = b = c = 0; };

	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

	line(point p, point q) {
		if(abs(p.x - q.x) < EPS) {
			//vertical
			b = 0.0;
			a = 1.0;
			c = -p.x;
		} else {
			b = 1.0;
			a = (q.y - p.y) / (p.x - q.x);
			c = -(a*p.x + p.y);
		}
	}

	line(point p, double m) {
		b = 1.0;
		a = -m;
		c = -(a*p.x + p.y);
	}

	bool parallel(line l) { return abs(a - l.a) < EPS && abs(b - l.b) < EPS; }

	bool same(line l) { return parallel(l) && abs(c - l.c) < EPS; }

	bool intersection(line l, point& p) {
		if(parallel(l)) return false;
		p.x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
		if(abs(b) < EPS)
			p.y = -(l.a * p.x + l.c);
		else
			p.y = -(a * p.x + c);
		return true;
	}

	point closest_point(point p) {
		if(abs(b) < EPS) return point(-c , p.y);
		if(abs(a) < EPS) return point(p.x , -c);
		point q;
		intersection(line(p, 1/a), q);
		return q;
	}
};

point point::reflection(line l) {
	point proj = l.closest_point(*this);
	vec v = make_vec(*this, proj);
	return translate(v).translate(v);
}

double point::dist_to_line(point a, point b) {
	line l(a, b);
	point proj = l.closest_point(*this);
	return dist(proj);
}

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

struct lineSegment {
	point a, b;

	lineSegment() {}

	lineSegment(point p, point q) : a(p), b(q) {}

	bool intersection(lineSegment ls, point& x) {
		line l1(a, b);
		line l2(ls.a, ls.b);
		if(l1.parallel(l2)) {
			if(l1.same(l2))
				return a.between(ls.a, ls.b) || b.between(ls.a, ls.b)
						|| ls.a.between(a, b) || ls.b.between(a, b);
			return false;
		}
		l1.intersection(l2, x);
		return x.between(a, b) && x.between(ls.a, ls.b);
	}

	bool operator< (const lineSegment& l) const {
		if(l.a == a)
			return l.b < b;
		return l.a < a;
	}
};

int n;
vector<double> memo;
vector<bool> vis;
vector<lineSegment> arr;

double fill(int idx) {
	if(vis[idx]) return memo[idx];
	point x(arr[idx].b.x, -INF);
	lineSegment fall(arr[idx].b, x);
	for(int i = idx + 1; i < n; i++)
		if(fall.intersection(arr[i], x))
			return memo[idx] = fill(i);
	vis[idx] = true;
	return memo[idx] = x.x;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc, q;
	cin >> tc;
	while(tc--) {
		cin >> n;
		arr.resize(n);
		memo.resize(n);
		vis.assign(n, false);
		int x, y;
		point a, b;
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			a = point(x, y);
			cin >> x >> y;
			b = point(x, y);
			arr[i] = lineSegment(max(a, b), min(a, b));
		}
		sort(all(arr));
		for(int i = 0; i < n; i++)
			fill(i);
		cin >> q;
		point p;
		while(q--) {
			cin >> x >> y;
			p = point(x, y);
			lineSegment fall(p, point(x, -INF));
			double ans = x;
			for(int i = 0; i < n; i++) {
				if(fall.intersection(arr[i], p)) {
					ans = memo[i];
					break;
				}
			}
			printf("%d\n", (int)round(ans));
		}
		if(tc) printf("\n");
	}
	return 0;
}
