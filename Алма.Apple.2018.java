import java.util.*;

class Alma {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int q, ans = 200000000;
      q = sc.nextInt();
      /// with horse
      ans = Math.min(ans, (q+19)/20+(q+19)/20-1);
      /// with donkey
      ans = Math.min(ans, ((q+199)/200)*5+((q+199)/200-1)*3);
      ///with both of them
      int a = q/200, b = q%200;
      if (b == 0) {
         ans = Math.min(ans, a*5+(a-1)*3);
      } else {
         ans = Math.min(ans, (b+19)/20+(b+19)/20-1+a*5+a*3);
      }
      System.out.println(ans);
   }
}
