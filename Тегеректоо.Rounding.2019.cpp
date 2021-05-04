#include <bits/stdc++.h>

using namespace std;

int main() {
   double k, n;
   cin >> k >> n;
   if (k < 20) {
      cout << ceil(k-pow(2.0, k) + sqrt(pow(4.0, k) + pow(2.0, k) * n)) << '\n';
   } else {
      cout << (int)(k + (n + 1) / 2) << '\n';
   }
   return 0;
}
