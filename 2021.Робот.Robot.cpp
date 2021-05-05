#include <iostream>
#include <set>
#include <tuple>

using namespace std;

set<tuple<int, int, int>> st;
int x, y, z;

int main() {
   cin.tie(0)->ios::sync_with_stdio(0);
   int n;
   cin >> n;

   st.insert({x, y, z});

   for (int i = 0; i < n; i++) {
      char a; int b;
      cin >> a >> b;
      int cnt = abs(b);
      while (cnt--) {
         x += (a == 'X' ? (b > 0 ? 1 : -1) : 0);
         y += (a == 'Y' ? (b > 0 ? 1 : -1) : 0);
         z += (a == 'Z' ? (b > 0 ? 1 : -1) : 0);
         st.insert({x, y, z});
      }
   }
   cout << st.size() << '\n';
   return 0;
}
