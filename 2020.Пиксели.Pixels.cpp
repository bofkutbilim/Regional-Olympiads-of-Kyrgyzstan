#include <iostream>
#include <set>
#include <map>

using namespace std;

const int N = 1000000;
int x1[3], Y1[3], x2[3], y2[3], z[3];
int field[N + 1][50];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   set<int> st;
   map<int, int> m;
   for (int i = 0; i < n; i++) {
      cin >> x1[i] >> Y1[i] >> x2[i] >> y2[i] >> z[i];
      if (x1[i] > x2[i]) swap(x1[i], x2[i]);
      if (Y1[i] > y2[i]) swap(Y1[i], y2[i]);
      st.insert(Y1[i] - 1);
      st.insert(Y1[i]);
      st.insert(Y1[i] + 1);
      st.insert(y2[i] - 1);
      st.insert(y2[i]);
      st.insert(y2[i] + 1);
   }
   int inv[st.size() + 1], k = 1;
   for (auto x : st) {
      m[x] = k;
      inv[k] = x;
      k++;
   }
   for (int i = 0; i < n; i++) {
      for (int X = x1[i]; X <= x2[i]; X++) {
         for (int Y = m[Y1[i]]; Y <= m[y2[i]]; Y++) {
            field[X][Y] = z[i];
         }
      }
   }
   int cnt = 0;
   for (int X = 0; X <= N; X++) {
      for (int Y = 0; Y < 50; Y++) {
         if (field[X][Y] == 1) {
            int j = Y;
            while (j < 50 && field[X][j] == 1)j++;
            j--;
            cnt += inv[j] - inv[Y] + 1;
            cnt %= 2019;
            Y = j;
         }
      }
   }
   cout << cnt << '\n';
   return 0;
}
