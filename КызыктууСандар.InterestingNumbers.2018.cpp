#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
   cin >> n;
   vector <int> ans {0, 11, 12, 14, 16, 21, 23, 25, 29,
      32, 34, 38, 41, 43, 47, 49, 52, 56, 58,
      61, 65, 67, 74, 76, 83, 85, 89,
      92, 94, 98, 111};
   if (n < ans.size())
      cout << ans[n] << '\n';
   else {
      n -= ans.size();
      string res = "112";
      while (n) {
         int index = -1;
         for (int i = res.size()-1; i >= 0; i--) {
            if (res[i] != '1') {
               index = i;
               break;
            }
         }
         if (index == 0) {
            if (res[index] == '0') res[index] = '2';
            else if (res[index] == '2') res[index] = '4';
            else if (res[index] == '4') res[index] = '6';
            else if (res[index] == '6') res[index] = '1', res = "1" + res, res[res.size()-1] = '0';
         } else {
            if (res[index] == '0') res[index] = '2';
            else if (res[index] == '2') res[index] = '4';
            else if (res[index] == '4') res[index] = '6';
            else if (res[index] == '6') res[index] = '1', res[index - 1] = '2';
         }
         n--;
      }
      if (res[res.size()-1] == '0')
         res[res.size()-1] = '1';
      cout << res << '\n';
   }
   return 0;
}
