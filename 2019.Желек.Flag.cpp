#include <iostream>
#include <cmath>

using namespace std;

double dist(int a, int b, int c, int d) {
   return ((a - c) * (a - c) + (b - d) * (b - d));
}

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int a, b, c, d, x;
   double A, B, C, D, ans = 0.0;
   cin >> a >> b >> c >> d;
   if (b == d) {
      if (abs(a - c) * 5 % 3 == 0) ans = max(ans, .0 + abs(a - c) * abs(a - c) * 5 / 3);
      if (abs(a - c) * 3 % 5 == 0) ans = max(ans, .0 + abs(a - c) * abs(a - c) * 3 / 5);
   }
   if (a == c) {
      if (abs(b - d) * 5 % 3 == 0) ans = max(ans, .0 + abs(b - d) * abs(b - d) * 5 / 3);
      if (abs(b - d) * 3 % 5 == 0) ans = max(ans, .0 + abs(b - d) * abs(b - d) * 3 / 5);
   }
   for (int e = -10000; e <= 10000; e++) {
      if (d - b == 0 || (c*c + d*d - a*c - b*d - c*e + a*e) % (d - b) != 0) goto next;
      x = (c*c + d*d - a*c - b*d - c*e + a*e) / (d - b);
      A = dist(a, b, c, d);
      B = dist(c, d, e, x);
      C = dist(a, b, e, x);
      if (A * 25 == B * 9 || A * 9 == B * 25)
         if (A + B == C)
            ans = max(ans, sqrt(A) * sqrt(B));
      next:;
      D = (b + d)*(b + d) - 4 * (e*e - a*e - e*c + a*c + b*d);
      if (D < 0) continue;
      int sq = sqrt(D);
      if (sq * sq != D) continue;
      if ((b + d + sq) % 2) continue;
      x = (b + d + sq) / 2;
      A = dist(a, b, e, x);
      B = dist(e, x, c, d);
      C = dist(a, b, c, d);
      if (A * 25 == B * 9 || A * 9 == B * 25)
         if (A + B == C)
            ans = max(ans, sqrt(A) * sqrt(B));
      x = b + d - sq;
      A = dist(a, b, e, x);
      B = dist(e, x, c, d);
      C = dist(a, b, c, d);
      if (A * 25 == B * 9 || A * 9 == B * 25)
         if (A + B == C)
            ans = max(ans, sqrt(A) * sqrt(B));
   }
   cout << round(ans);
   return 0;
}
