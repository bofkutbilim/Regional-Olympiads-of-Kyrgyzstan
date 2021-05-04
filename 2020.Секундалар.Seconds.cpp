#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   vector <int> a(n), b(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   for (int i = 0; i < n; i++) {
      cin >> b[i];
   }
   int l = -1, r = -1;
   for (int i = 0; i < 60; i++) {
      bool flag = true;
      for (int j = 0; j < n; j++) {
         if ((i + a[j]) / 60 != b[j]) flag = false;
      }
      if (flag) r = i;
      if (flag && l == -1) l = i;
   }
   cout << l << ' ' << r << '\n';
   return 0;
}
