#include <bits/stdc++.h>

using namespace std;

int main() {
   cin.tie(0)->ios::sync_with_stdio(0);
   int n, q;
   cin >> n >> q;
   pair<int, int> a[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
   }
   sort(a, a + n);
   while (q --) {
      int l, r;
      cin >> l >> r;
      long long ans = 0ll;
      int x = 1;
      for (int i = 0; i < n; i++) {
         if (a[i].second >= l && a[i].second <= r) {
            if (x) {
               ans -= a[i].first;
            } else {
               ans += a[i].first;
            }
            x ^= 1;
         }
      }
      cout << ans << '\n';
   }
   return 0;
}
