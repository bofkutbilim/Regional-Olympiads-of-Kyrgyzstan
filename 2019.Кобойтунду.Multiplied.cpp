#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int a, b, c;
   int ans = 0;
   cin >> a >> b >> c;
   size_t maxsize = 0, minsize = 2e9;
   for (int cntb = 0; a - b * cntb >= 0; cntb++) {
      if ((a - b * cntb) % c == 0) {
         int cntc = (a - b * cntb) / c;
         maxsize = max(maxsize, (size_t)(cntb+cntc));
         minsize = min(minsize, (size_t)(cntb+cntc));
      }
   }
   if (maxsize == 0)
      return cout << "-1\n", 0;
   if (maxsize <= 18) {
      for (int cntb = 0; a - b * cntb >= 0; cntb++) {
         if ((a - b * cntb) % c == 0) {
            int cntc = (a - b * cntb) / c;
            int num = cntb, res = 1;
            while (num--) res *= b;
            num = cntc;
            while (num--) res *= c;
            ans = max(ans, res);
         }
      }
      cout << ans % 1000;
      return 0;
   }
   for (int cntb = 0; a - b * cntb >= 0; cntb++) {
      if ((a - b * cntb) % c == 0) {
         int cntc = (a - b * cntb) / c;
         if (min(b, c) == 1 && (cntb + cntc) == minsize) {
            int num = cntb, res = 1;
            while (num--) res = res * b % 1000;
            num = cntc;
            while (num--) res = res * c % 1000;
            ans = res;
         } else if (min(b, c) > 1 && (cntb + cntc) == maxsize) {
            int num = cntb, res = 1;
            while (num--) res = res * b % 1000;
            num = cntc;
            while (num--) res = res * c % 1000;
            ans = res;
         }
      }
   }
   cout << ans << '\n';
   return 0;
}
