#include <bits/stdc++.h>

using namespace std;

int main() {
   auto next = [](string &s) -> void {
      int i = s.size() - 1;
      while (s[i] == 'Z') {
         s[i] = 'A';
         i--;
      }
      s[i]++;
   };
   string str;
   cin >> str;
   while ( true ) {
      next(str);
      int cnta = 0,cnte = 0, cnti = 0, cnto = 0, cnty = 0;
      for (int i = 0; i < str.size(); i++) {
         if (str[i] == 'A') cnta = 1;
         if (str[i] == 'E') cnte = 1;
         if (str[i] == 'I') cnti = 1;
         if (str[i] == 'O') cnto = 1;
         if (str[i] == 'Y') cnty = 1;
      }
      if (cnta+cnte+cnti+cnto+cnty == 1)
         return cout << str, 0;
   }
   return 0;
}
