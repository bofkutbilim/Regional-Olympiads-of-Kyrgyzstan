#include <iostream>

using namespace std;

int main(){
   unsigned long long m, n;
   cin >> m >> n;
   m % 2 == 0?
   cout << ((m*m*m*m*m)/2%n) * ((m*m*m*m*m+17)%n)%n :
   cout << (((m*m*m*m*m)%n) * ((m*m*m*m*m+17)/2%n)%n);
   return 0;
}
