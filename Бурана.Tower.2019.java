import java.util.*;
import java.lang.*;
import java.io.*;

class Tegerektoo{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] mas = new int[300];
		for (int i = 0; i < 300; i++)
			mas[i] = 0;
	    int a = sc.nextInt(), t = sc.nextInt(), b = sc.nextInt(), ans = 0;
	    int i = 1;
	    while (a-- > 0) {
	        while (mas[i] > 0) i++;
	        mas[i] = 1;
	        mas[i + 6] = 1;
	    }
	    i = t + 1;
	    while (b-- > 0) {
	        while (mas[i] > 0) i++;
	        mas[i] = 1;
	        mas[i + 6] = 1;
	    }
	    for (i = 0; i < 300; i++) {
	        if (mas[i] > 0) ans = i;
	    }
	    System.out.println(ans);
	}
}
