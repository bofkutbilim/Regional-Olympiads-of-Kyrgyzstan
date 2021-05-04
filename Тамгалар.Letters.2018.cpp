#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int x1, y1, x2, y2, d1, d2;
   cin >> x1 >> y1 >> d1;
   cin >> x2 >> y2 >> d2;
   map<pair<int, int>, int> m;
   d1 = (d1 + 1) / 2;
   d2 = (d2 + 1) / 2;

   for(int y = (y1 - d1); y <= (y1 + d1); y++)
      m[ make_pair(y, x1) ] = 1;

   for(int x = (x2 - d2); x <= (x2 + d2); x++)
      m[ make_pair(y2, x) ] = 1;

   for (int x = (x2 - d2), y = y2; x <= (x2 + d2); x++){
      int a = 0, b = 0, c = 0, d = 0;
      if (m[ make_pair(y - 1, x) ] == 1) a = 1;
      if (m[ make_pair(y + 1, x) ] == 1) b = 1;
      if (m[ make_pair(y, x + 1) ] == 1) c = 1;
      if (m[ make_pair(y, x - 1) ] == 1) d = 1;
      if (a + b + c + d == 4) {
         return cout << 'X', 0;
      }
      if (a + b + c + d == 3){
         return cout << 'T', 0;
      }
      if (a + b < 2 && c + d < 2 && a + b + c + d == 2) {
         return cout << 'L', 0;
      }
   }
   return cout << 'A', 0;
}
