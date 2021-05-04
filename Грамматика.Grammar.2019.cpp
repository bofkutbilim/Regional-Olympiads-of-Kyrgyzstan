#include <iostream>

using namespace std;

#define endl '\n'
#define pb push_back

bool Glas(char ch){
   if(ch == 'A' || ch == 'E' || ch == 'I' ||
   ch == 'O' || ch == 'U' || ch == 'Y') return 1;
   return 0;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n; cin >> n;
   string str; cin >> str;
   int i = str.size()-1;
   if(n == 2){
      if(str[i] == 'A') cout << str << "NYN";
      else if(str[i] == 'E') cout << str << "NIN";
      else if(str[i] == 'I') cout << str << "NIN";
      else if(str[i] == 'O') cout << str << "NUN";
      else if(str[i] == 'U') cout << str << "NUN";
      else if(str[i] == 'Y') cout << str << "NYN";
      else{
         char orto;
         while(!Glas(str[i])) i--;
         int j = i;
         i = str.size()-1;

         if(str[j] == 'A' || str[j] == 'Y')
         orto = 'Y';
         if(str[j] == 'E' || str[j] == 'I')
         orto = 'I';
         if(str[j] == 'O' || str[j] == 'U')
         orto = 'U';

         if(str[i] == 'B') cout << str << "T" <<orto << "N";
         else if(str[i] == 'D') cout << str << "D"<<orto  << "N";
         else if(str[i] == 'G') cout << str << "T"<<orto <<"N";
         else if(str[i] == 'K') cout << str << "T"<<orto <<"N";
         else if(str[i] == 'L') cout << str << "D"<<orto <<"N";
         else if(str[i] == 'M') cout << str << "D"<<orto <<"N";
         else if(str[i] == 'N') cout << str << "D"<<orto <<"N";
         else if(str[i] == 'P') cout << str << "T"<<orto <<"N";
         else if(str[i] == 'R') cout << str << "D"<<orto <<"N";
         else if(str[i] == 'S') cout << str << "T"<<orto <<"N";
         else if(str[i] == 'T') cout << str << "T"<<orto <<"N";
      }
   } else if(n == 3){
      if(str[i] == 'A') cout << str << "GA";
      else if(str[i] == 'E') cout << str << "GE";
      else if(str[i] == 'I') cout << str << "GE";
      else if(str[i] == 'O') cout << str << "GO";
      else if(str[i] == 'U') cout << str << "GA";
      else if(str[i] == 'Y') cout << str << "GA";
      else{
         char orto;
         while(!Glas(str[i])) i--;
         int j = i;
         i = str.size()-1;

         if(str[j] == 'A' || str[j] == 'Y' || str[j] == 'U')
         orto = 'A';
         if(str[j] == 'E' || str[j] == 'I')
         orto = 'E';
         if(str[j] == 'O')
         orto = 'O';


         if(str[i] == 'B') cout << str << "K" <<orto;
         else if(str[i] == 'D') cout << str << "K"<<orto;
         else if(str[i] == 'G') cout << str << "K"<<orto;
         else if(str[i] == 'K') cout << str << "K"<<orto;
         else if(str[i] == 'L') cout << str << "G"<<orto;
         else if(str[i] == 'M') cout << str << "G"<<orto;
         else if(str[i] == 'N') cout << str << "G"<<orto;
         else if(str[i] == 'P') cout << str << "K"<<orto;
         else if(str[i] == 'R') cout << str << "G"<<orto;
         else if(str[i] == 'S') cout << str << "K"<<orto;
         else if(str[i] == 'T') cout << str << "K"<<orto;
      }
   }else if(n == 4){
      if(str[i] == 'A') cout << str << "NY";
      else if(str[i] == 'E') cout << str << "NI";
      else if(str[i] == 'I') cout << str << "NI";
      else if(str[i] == 'O') cout << str << "NU";
      else if(str[i] == 'U') cout << str << "NU";
      else if(str[i] == 'Y') cout << str << "NY";
      else{
         char orto;
         while(!Glas(str[i])) i--;
         int j = i;
         i = str.size()-1;

         if(str[j] == 'A' || str[j] == 'Y')
         orto = 'Y';
         if(str[j] == 'E' || str[j] == 'I')
         orto = 'I';
         if(str[j] == 'O' || str[j] == 'U')
         orto = 'U';

         if(str[i] == 'B') cout << str << "T" <<orto;
         else if(str[i] == 'D') cout << str << "T"<<orto;
         else if(str[i] == 'G') cout << str << "T"<<orto;
         else if(str[i] == 'K') cout << str << "T"<<orto;
         else if(str[i] == 'L') cout << str << "D"<<orto;
         else if(str[i] == 'M') cout << str << "D"<<orto;
         else if(str[i] == 'N') cout << str << "D"<<orto;
         else if(str[i] == 'P') cout << str << "T"<<orto;
         else if(str[i] == 'R') cout << str << "D"<<orto;
         else if(str[i] == 'S') cout << str << "T"<<orto;
         else if(str[i] == 'T') cout << str << "T"<<orto;
      }
   }else if(n == 5){
      if(str[i] == 'A') cout << str << "DA";
      else if(str[i] == 'E') cout << str << "DE";
      else if(str[i] == 'I') cout << str << "DE";
      else if(str[i] == 'O') cout << str << "DO";
      else if(str[i] == 'U') cout << str << "DA";
      else if(str[i] == 'Y') cout << str << "DA";
      else{
         char orto;
         while(!Glas(str[i])) i--;
         int j = i;
         i = str.size()-1;

         if(str[j] == 'A' || str[j] == 'Y' || str[j] == 'U')
         orto = 'A';
         if(str[j] == 'E' || str[j] == 'I')
         orto = 'E';
         if(str[j] == 'O')
         orto = 'O';


         if(str[i] == 'B') cout << str << "T" <<orto;
         else if(str[i] == 'D') cout << str << "T"<<orto;
         else if(str[i] == 'G') cout << str << "T"<<orto;
         else if(str[i] == 'K') cout << str << "T"<<orto;
         else if(str[i] == 'L') cout << str << "D"<<orto;
         else if(str[i] == 'M') cout << str << "D"<<orto;
         else if(str[i] == 'N') cout << str << "D"<<orto;
         else if(str[i] == 'P') cout << str << "T"<<orto;
         else if(str[i] == 'R') cout << str << "D"<<orto;
         else if(str[i] == 'S') cout << str << "T"<<orto;
         else if(str[i] == 'T') cout << str << "T"<<orto;
      }
   }else if(n == 6){
      if(str[i] == 'A') cout << str << "DAN";
      else if(str[i] == 'E') cout << str << "DEN";
      else if(str[i] == 'I') cout << str << "DEN";
      else if(str[i] == 'O') cout << str << "DON";
      else if(str[i] == 'U') cout << str << "DAN";
      else if(str[i] == 'Y') cout << str << "DAN";
      else{
      char orto;
         while(!Glas(str[i])) i--;
         int j = i;
         i = str.size()-1;

         if(str[j] == 'A' || str[j] == 'Y' || str[j] == 'U')
         orto = 'A';
         if(str[j] == 'E' || str[j] == 'I')
         orto = 'E';
         if(str[j] == 'O')
         orto = 'O';


         if(str[i] == 'B') cout << str << "T" <<orto << "N";
         else if(str[i] == 'D') cout << str << "T"<<orto<< "N";
         else if(str[i] == 'G') cout << str << "T"<<orto<< "N";
         else if(str[i] == 'K') cout << str << "T"<<orto<< "N";
         else if(str[i] == 'L') cout << str << "D"<<orto<< "N";
         else if(str[i] == 'M') cout << str << "D"<<orto<< "N";
         else if(str[i] == 'N') cout << str << "D"<<orto<< "N";
         else if(str[i] == 'P') cout << str << "T"<<orto<< "N";
         else if(str[i] == 'R') cout << str << "D"<<orto<< "N";
         else if(str[i] == 'S') cout << str << "T"<<orto<< "N";
         else if(str[i] == 'T') cout << str << "T"<<orto<< "N";
      }
   }
   return 0;
}
