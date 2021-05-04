#include <bits/stdc++.h>

using namespace std;

#define int long long

struct point {
   int x, y;
};

struct segment {
   point a, b;
};

int sq(segment sc) {
   return max(0ll, sc.b.x-sc.a.x+1) * max(0ll, sc.b.y-sc.a.y+1);
}

int intersect(segment fr, segment sc) {
   sc.b.x = min(sc.b.x, fr.b.x);
   sc.b.y = min(sc.b.y, fr.b.y);

   sc.a.x = max(sc.a.x, fr.a.x);
   sc.a.y = max(sc.a.y, fr.a.y);

   return sq(sc);
}

segment inter(segment fr, segment sc) {
   sc.b.x = min(sc.b.x, fr.b.x);
   sc.b.y = min(sc.b.y, fr.b.y);

   sc.a.x = max(sc.a.x, fr.a.x);
   sc.a.y = max(sc.a.y, fr.a.y);
   return sc;
}

int mas[5001][5001];

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   segment s[n];
   int z[n];
   bool flag = true;
   for (int i = 0; i < n; i++) {
      cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y >> z[i];
      if (s[i].a.x > s[i].b.x) swap(s[i].a.x, s[i].b.x);
      if (s[i].a.y > s[i].b.y) swap(s[i].a.y, s[i].b.y);
      if (s[i].b.x > 5000 || s[i].b.y > 5000)
      flag = false;
   }
   if (flag) {
      for (int i = 0; i < n; i++) {
         for (int x = s[i].a.x; x <= s[i].b.x; x++) {
            for (int y = s[i].a.y; y <= s[i].b.y; y++)
              mas[x][y] = z[i];
         }
      }
      int cnt = 0;
      for (int i = 0; i < 5001; i++) {
         for (int j = 0; j < 5001; j++)
         if (mas[i][j] == 1) cnt++;
      }
      cout << cnt % 2019 << '\n';
   } else if (n == 1) {
      if (z[0] != 1) cout << 0;
      else cout << sq(s[0]) % 2019;
   } else if (n == 2) {
      if (z[0] == 1 && z[1] == 1)
         cout << (sq(s[0]) + sq(s[1]) - intersect(s[0], s[1])) % 2019;
      else if (z[0] == 1 && z[1] != 1)
         cout << (sq(s[0]) - intersect(s[0], s[1])) % 2019;
      else if (z[0] != 1 && z[1] == 1)
         cout << (sq(s[1])) % 2019;
      else cout << 0;
   } else if (n == 3 && z[0] == 1 && z[1] != 1 && z[2] != 1) {
      int X1, Y1, X2, Y2, ans = sq(s[0]);
      X1 = max(s[0].a.x, s[1].a.x);
      Y1 = max(s[0].a.y, s[1].a.y);
      X2 = min(s[0].b.x, s[1].b.x);
      Y2 = min(s[0].b.y, s[1].b.y);
      ans -= (X2-X1+1>=0?X2-X1+1:0)*(Y2-Y1+1>=0?Y2-Y1+1:0);

      X1 = max(s[0].a.x, s[2].a.x);
      Y1 = max(s[0].a.y, s[2].a.y);
      X2 = min(s[0].b.x, s[2].b.x);
      Y2 = min(s[0].b.y, s[2].b.y);
      ans -= (X2-X1+1>=0?X2-X1+1:0)*(Y2-Y1+1>=0?Y2-Y1+1:0);

      X1 = max(s[1].a.x, s[2].a.x);
      Y1 = max(s[1].a.y, s[2].a.y);
      X2 = min(s[1].b.x, s[2].b.x);
      Y2 = min(s[1].b.y, s[2].b.y);

      X1 = max(X1, s[0].a.x);
      X2 = min(X2, s[0].b.x);
      Y1 = max(Y1, s[0].a.y);
      Y2 = min(Y2, s[0].b.y);
      ans += (X2-X1+1>=0?X2-X1+1:0)*(Y2-Y1+1>=0?Y2-Y1+1:0);

      cout << ans % 2019;
   } else {
      assert(false);
   }
   return 0;
}
