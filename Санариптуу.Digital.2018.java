import java.util.*;

class Sanariptuu {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long ans = 0;
      ans += n;
      ans += (n - 1) * n;
      for (int i = 1; i <= n; i++) {
         int m = (n - i);
         ans += (m - 1) * m / 2;
      }
      System.out.println(ans);
   }
}
