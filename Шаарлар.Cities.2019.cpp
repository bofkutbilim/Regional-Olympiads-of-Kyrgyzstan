#include <bits/stdc++.h>

using namespace std;

int dist[9][9];

int B = 0, A = 1, J = 2,
T = 3, O = 4, K = 5,
L = 6, N = 7, E = 8;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   vector <pair<int,int> > g[9];
   g[B].push_back({A, 193});
   g[A].push_back({B, 193});
   dist[A][B] = dist[B][A] = 193;

   g[T].push_back({A, 102});
   g[A].push_back({T, 102});
   dist[A][T] = dist[T][A] = 102;

   g[J].push_back({A, 377});
   g[A].push_back({J, 377});
   dist[A][J] = dist[J][A] = 377;

   g[J].push_back({O, 106});
   g[O].push_back({J, 106});
   dist[J][O] = dist[O][J] = 106;

   g[E].push_back({O, 240});
   g[O].push_back({E, 240});
   dist[O][E] = dist[E][O] = 240;

   g[B].push_back({L, 179});
   g[L].push_back({B, 179});
   dist[L][B] = dist[B][L] = 179;


   g[K].push_back({L, 216});
   g[L].push_back({K, 216});
   dist[K][L] = dist[L][K] = 216;

   g[L].push_back({N, 180});
   g[N].push_back({L, 180});
   dist[N][L] = dist[L][N] = 180;

   char from, to;
   cin >> from >> to;
   int D, a, b;
   cin >> D;
   if (from == 'A') a = A;
   if (from == 'B') a = B;
   if (from == 'T') a = T;
   if (from == 'J') a = J;
   if (from == 'K') a = K;
   if (from == 'L') a = L;
   if (from == 'N') a = N;
   if (from == 'E') a = E;
   if (from == 'O') a = O;

   if (to == 'A') b = A;
   if (to == 'B') b = B;
   if (to == 'T') b = T;
   if (to == 'J') b = J;
   if (to == 'K') b = K;
   if (to == 'L') b = L;
   if (to == 'N') b = N;
   if (to == 'E') b = E;
   if (to == 'O') b = O;

   set<pair<int, int>> st;
   vector <int> used(9, 0), d(9, 2e9), p(9, -1);
   st.insert({0, a});
   d[a] = 0;
   while (!st.empty()) {
      int v = st.begin()->second;
      st.erase(st.begin());
      if (used[v]) continue;
      used[v] = 1;
      for (auto i: g[v]) {
         int to = i.first, len = i.second;
         if (d[v] + len < d[to]) {
            d[to] = d[v] + len;
            p[to] = v;
            st.insert({d[to], to});
         }
      }
   }
   vector <int> shaar;
   int v = b;
   while (v != -1) {
      shaar.push_back(v);
      v = p[v];
   }
   reverse(shaar.begin(), shaar.end());
   int res = 0, oldres = 0;
   for (int i = 1; i < shaar.size(); i++) {
      res += dist[shaar[i]][shaar[i-1]];
      if (res >= D) {
         return cout << min(res-D,D-oldres),0;
      }
      oldres = res;
   }
   cout << 0;
   return 0;
}
