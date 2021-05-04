import java.util.*;

class Somdor {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int s = sc.nextInt();
      for (int i = 0; i <= a; i++) {
         for (int j = 0; j <= b; j++) {
            if (i * 3 + j * 10 == s) {
               System.out.println(i + j);
               return;
            }
         }
      }
      System.out.println(0);
   }
}
