#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int M, J, T, ans = 0;
   cin >> M >> J >> T;
   while (M < T) {
      ans += 20;
      J += M;
      T -= M;
   }
   ans += 20;
   int cur = min(J, M - T);
   J -= cur;
   J += T;
   while (J) {
      int cur = min(J, M);
      J -= cur;
      ans += 20;
   }
   ans -= 10;
   cout << ans << '\n';
   return 0;
}
