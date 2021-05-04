#include <iostream>
#include <map>
#include <set>
using namespace std;

set<char> ch;

map<char, int> init(string a) {
   map<char, int> m;
   for (int i = 0; i < a.size(); i++) {
      if (isalpha(a[i])) {
         ch.insert(a[i]);
         if (i + 1 == a.size()) m[a[i]] ++;
         else if (isalpha(a[i + 1])) m[a[i]]++;
         else m[a[i]] += (a[i + 1] - '0');
      }
   }
   return m;
}

int main() {
   string a; cin >> a;
   string b; cin >> b;
   string c; cin >> c;
   map<char, int> ma = init(a);
   map<char, int> mb = init(b);
   map<char, int> mc = init(c);
   map<char, int> res;
   for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
         for (int k = 1; k <= 100; k++) {
            int f = 1;
            for (auto x: ch) {
               if (ma[x] * i + mb[x] * j != mc[x] * k)
               f = 0;
            }
            if (f)return cout << i << ' ' << j << ' ' << k, 0;
         }
      }
   }
   cout << "0 0 0";
   return 0;
}
