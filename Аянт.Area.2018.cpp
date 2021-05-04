#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define x first
#define y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double a, b, m, k;
	cin >> a >> b >> m >> k;
	vector<pair<double, double> > vec;
	vec.push_back(make_pair(.0, .0));
	for (int x = 0; x <= m; x++) {
		double y = (a * b - a * x) / b;
		if (y < 0) y = 0;
		if (y > k) y = k;
		vec.push_back(make_pair(x, y));
	}
	vec.push_back(make_pair(m, .0));
	vec.push_back(make_pair(.0, .0));
	double s[] = {.0, .0};
	for (int i = 0; i < vec.size() - 1; i++) {
		s[0] += vec[i].x * vec[i + 1].y;
		s[1] += vec[i].y * vec[i + 1].x;
	}
	cout << ceil(fabs(s[0] - s[1]) / 2.0);
	return 0;
}
