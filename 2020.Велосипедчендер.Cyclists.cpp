#include <bits/stdc++.h>

using namespace std;

#define int long long
#define f first
#define s second

pair <double, double> a[3], b[3], c[3];
double ans, x;

signed main() {
   cin >> x; a[0] = make_pair(x, x / 2.0);
   cin >> x; a[1] = make_pair(x, x / 2.0);
   cin >> x; a[2] = make_pair(x, x / 2.0);
   sort (a, a + 3);
   reverse(a, a + 3);
   for (double i = 0.5; i <= min({a[0].s, a[1].f, a[2].f}); i += 0.5){

      b[0] = make_pair((a[0].s - i) * 2, a[0].s - i);
      b[1] = make_pair(a[1].f - i, (a[1].f - i) / 2);
      b[2] = make_pair(a[2].f - i, (a[2].f - i) / 2);

      for (double j = 0.5; j <= min({b[1].s, b[0].f, b[2].f}); j += 0.5) {

         c[1] = make_pair((b[1].s - j) * 2, b[1].s - j);
         c[0] = make_pair(b[0].f - j, (b[0].f - j) / 2);
         c[2] = make_pair(b[2].f - j, (b[2].f - j) / 2);

         ans = max(ans, i + j + min({c[2].s, c[0].f, c[1].f}));
      }
   }
   cout <<  (int)(ans) << '\n';
   return 0;
}
