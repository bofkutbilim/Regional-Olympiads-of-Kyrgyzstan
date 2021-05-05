#include <bits/stdc++.h>

using namespace std;

int main() {
   cin.tie(0)->ios::sync_with_stdio(0);
   int n;
   cin >> n;
   int a[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   priority_queue<int> q;
   long long s = 0;
   for (int i = 0; i < n; i++) {
      int type;
      cin >> type;
      if (type == 1) {
         s = s + a[i];
      } else {
         if (s >= a[i]) {
            s = s - a[i];
            q.push(a[i]);
         } else {
            if (!q.empty() && q.top() >= a[i]) {
               s = s + q.top() - a[i];
               q.pop();
               q.push(a[i]);
            }
         }
      }
   }
   cout << q.size() << '\n';
   return 0;
}
