#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
   int a, b, c, bc, ans = 0;
   cin >> a;
   for (int sum = 7; sum <= a + a + a; sum += 7) {
      int bc = sum - a;
      if (bc <= a) continue;
         if (bc % 2 == 0) {
         int A = a;
         b = c = bc / 2;
         if (b == 0) b++;
         ans += max(0ll, A - b + 1);
      } else {
         int A = a;
         b = c = bc / 2;
         if (b == 0) b++;
         ans += max(0ll, A - b);
      }
   }
   cout << ans % 1000 << '\n';
   return 0;
}
