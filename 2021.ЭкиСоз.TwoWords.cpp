#include <bits/stdc++.h>

using namespace std;

int dp[2000][2000];

int main() {
   cin.tie(0)->ios::sync_with_stdio(0);
   string a;
   string b;
   cin >> a >> b;
   int n = a.size();
   int m = b.size();
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (a[i - 1] == b[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
         } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
   }
   cout << n + m - 2 * dp[n][m] << '\n';
   return 0;
}
