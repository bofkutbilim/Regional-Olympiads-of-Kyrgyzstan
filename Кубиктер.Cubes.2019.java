import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Kubikter{
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] dp = new int[10000];
      for (int i = 0; i < 10000; i++)
      dp[i] = 0;
      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
         dp[i] = dp[i - 1] + 1;
         for (int j = 1; j * j * j <= i; j++) {
            if (j * j * j == i)
               dp[i] = 1;
            dp[i] = Math.min(dp[i], dp[j * j * j] + dp [i - j * j * j]);
         }
      }
      System.out.println(dp[n]);
   }
}
