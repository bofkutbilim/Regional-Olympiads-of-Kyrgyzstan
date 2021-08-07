#include <bits/stdc++.h>

using namespace std;

long long tree[3 * 100000 * 4];
int treesize;

void add(int pos, int val, int v = 0, int vl = 0, int vr = treesize - 1) {
   if (vl == vr)
      tree[v] += val;
   else {
      int vm = (vl + vr) / 2;
      if (pos <= vm)
         add(pos, val, 2 * v + 1, vl, vm);
      else
         add(pos, val, 2 * v + 2, vm + 1, vr);
      tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
   }
}

long long get(int l, int r, int v = 0, int vl = 0, int vr = treesize - 1) {
   if (l > vr || vl > r)
      return 0;
   if (l <= vl && vr <= r)
      return tree[v];
   int vm = (vl + vr) / 2;
   long long g1 = get(l, r, 2 * v + 1, vl, vm);
   long long g2 = get(l, r, 2 * v + 2, vm + 1, vr);
   return g1 + g2;
}

int main() {
   int n, q, m;
   cin >> n >> q >> m;
   treesize = q;
   vector<pair<int, int>> vec[n + 1];
   vector<pair<int, int>> g[n + 1];
   int ans[m];

   for (int i = 0; i < q; i++) {
      int l, r, x;
      cin >> l >> r >> x;
      vec[l].push_back({x, i});
      if (r + 1 <= n) vec[r + 1].push_back({-x, i});
   }
   for (int i = 0; i < m; i++) {
      int pos, x;
      cin >> pos >> x;
      g[pos].push_back({x, i});
      ans[i] = -1;
   }
   for (int i = 1; i <= n; i++) {
      sort(vec[i].begin(), vec[i].end());
      sort(g[i].begin(), g[i].end());
   }
   for (int i = 1; i <= n; i++) {
      for (auto it : vec[i]) {
         add(it.second, it.first);
      }
      for (auto it : g[i]) {
         int l = 0, r = q - 1;
         while (l < r) {
            int m = (l + r) / 2;
            if (get(0, m) >= it.first)
               r = m;
            else
               l = m + 1;
         }
         if (get(0, r) >= it.first)
            ans[it.second] = r;
      }
   }
   for (int i = 0; i < m; i++) {
      if (ans[i] == -1) cout << "-1\n";
      else cout << ans[i] + 1 << '\n';
   }
   return 0;
}
