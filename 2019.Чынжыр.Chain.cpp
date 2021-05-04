#include <iostream>

using namespace std;

#define endl '\n'

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int n, k, Ans = 0;
   cin >> n >> k;
   if (k == 1) {
      Ans = (n * (n + 1) / 2 - 1) % 1000;
   } else if (k == 2) {
      for (int a = 1; a <= n; a++) {
         for (int b = a; b <= n; b++) {
            int m = n - b - 1;
            Ans += m * (m + 1) / 2;
            Ans %= 1000;
         }
      }
   } else {
      for (int a =  1; a <= n; a++) {
         for (int b =  a; b <= n; b++) {
            for (int c =b+2; c <= n; c++) {
               for (int d =  c; d <= n; d++) {
                  int m = n - d - 1;
                  Ans += m * (m + 1) / 2;
                  Ans %= 1000;
               }
            }
         }
      }
   }
   cout << Ans%1000;
   return (0);
}
