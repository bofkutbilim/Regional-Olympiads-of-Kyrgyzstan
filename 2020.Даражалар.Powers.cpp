#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int a, b, c, d, f;
   cin >> a >> b >> c >> d >> f;
   auto primes = [](int n) -> vector<int> {
      vector <int> res;
      for (int i = 2; i * i <= n; i++) {
         while (n % i == 0) {
            res.push_back(i);
            n /= i;
         }
      }
      if (n > 1) {
         res.push_back(n);
      }
      return res;
   };
   vector <int> res1 = primes(a);
   vector <int> res2 = primes(c);
   map <int,int> ans1;
   for (int it: res1) ans1[it] += b;
   map <int,int> ans2;
   for (int it: res2) ans2[it] += d;
   int ans = 1;
   for (auto a: ans1) {
      a.second = min(a.second, ans2[a.first]);
      while (a.second--) ans = ans * a.first % f;
   }
   cout << ans << '\n';
   return 0;
}
