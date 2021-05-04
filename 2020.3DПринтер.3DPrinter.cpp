#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long x[4], y[4], z[4];

bool arzhak(int x1, int y1, int x2, int y2) {
   return abs(x1 - x2) + abs(y1 - y2) > 1;
}
bool bir(int x1, int y1, int x2, int y2) {
   return abs(x1 - x2) + abs(y1 - y2) == 1;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i] >> z[i];
   if (n == 1) {
      cout << x[0] + y[0] + z[0];
   } else if (n == 2) {
      if (x[0] == x[1] && y[0] == y[1]) {
         cout << x[0] + y[0] + max(z[0], z[1]);
      } else if (abs(x[1] - x[0]) + abs(y[1] - y[0]) == 1) {
         long long ans = x[0] + y[0] + z[0] + z[0] + abs(x[1] - x[0]) + abs(y[1] - y[0]) + z[1];
         ans = min(ans, x[1] + y[1] + z[1] + z[1] + abs(x[1] - x[0]) + abs(y[1] - y[0]) + z[0]);
         ans = min(ans, x[0] + y[0] + max(z[1], z[0]) + 1 + max(z[1], z[0]));
         ans = min(ans, x[1] + y[1] + max(z[1], z[0]) + 1 + max(z[1], z[0]));
         if (z[0] < z[1]) {
            ans = min(ans, x[0] + y[0] + (z[0] % 2 ? z[0] * 2 : z[0] * 2 + 1) + z[1] - z[0]);
            ans = min(ans, x[1] + y[1] + (z[0] % 2 ? z[0] * 2 + 1 : z[0] * 2) + z[1] - z[0]);
         } else {
            ans = min(ans, x[1] + y[1] + (z[1] % 2 ? z[1] * 2 : z[1] * 2 + 1) + z[0] - z[1]);
            ans = min(ans, x[0] + y[0] + (z[1] % 2 ? z[1] * 2 + 1 : z[1] * 2) + z[0] - z[1]);
         }
         cout << ans;
      } else {
         long long ans = x[0] + y[0] + z[0] + z[0] + abs(x[1] - x[0]) + abs(y[1] - y[0]) + z[1];
         ans = min(ans, x[1] + y[1] + z[1] + z[1] + abs(x[1] - x[0]) + abs(y[1] - y[0]) + z[0]);
         cout << ans;
      }
   } else if (n == 3) {
      int per[] = {0, 1, 2}, flag;
      if (arzhak(x[0], y[0], x[1], y[1]) && arzhak(x[0], y[0], x[2], y[2]) && arzhak(x[2], y[2], x[1], y[1])) {
         per[0] = 0; per[1] = 1; per[2] = 2;
         long long ans = 9e18;
         do {
         ans = min(ans, x[per[0]] + y[per[0]] + z[per[0]] * 2 + abs(x[per[1]] - x[per[0]]) +
           abs(y[per[1]] - y[per[0]]) + z[per[1]] * 2 + abs(x[per[2]] - x[per[1]]) +
           abs(y[per[2]] - y[per[1]]) + z[per[2]]);
         } while (next_permutation(per, per + 3));
         return cout << ans, 0;
      }
      per[0] = 0; per[1] = 1; per[2] = 2;
      flag = false;
      do {
         if (bir(x[per[0]], y[per[0]], x[per[1]], y[per[1]]) && bir(x[per[1]], y[per[1]], x[per[2]], y[per[2]])) {
            flag = true;
            break;
         }
      } while (next_permutation(per, per + 3));
      if (flag) {
         if (z[per[0]] == z[per[1]] && z[per[1]] == z[per[2]]) {
            long long ans = min(x[per[0]] + y[per[0]], x[per[2]] + y[per[2]]) + z[per[0]] * 3;
            return cout << ans, 0;
         } else if (z[per[0]] <= z[per[1]] && z[per[1]] <= z[per[2]]) {
            long long ans = x[per[2]] + y[per[2]] + z[per[0]] + z[per[1]] + z[per[2]];
            return cout << ans, 0;
         }
      }
      per[0] = 0; per[1] = 1; per[2] = 2;
      flag = false;
      do {
         if (bir(x[per[0]], y[per[0]], x[per[1]], y[per[1]]) && arzhak(x[per[1]], y[per[1]], x[per[2]], y[per[2]])) {
            flag = true;
            break;
         }
      } while (next_permutation(per, per + 3));
      if (flag) {
         long long ans = x[per[0]] + y[per[0]] + max(z[per[0]], z[per[1]]) * 2 + 1 + abs(x[per[2]] - x[per[1]]) + abs(y[per[2]] - y[per[1]]) + z[per[2]];
         ans = min(ans, x[per[1]] + y[per[1]] + max(z[per[0]], z[per[1]]) * 2 + 1 + abs(x[per[2]] - x[per[0]]) + abs(y[per[2]] - y[per[0]]) + z[per[2]]);
         return cout << ans, 0;
      }
   }
   return 0;
}
