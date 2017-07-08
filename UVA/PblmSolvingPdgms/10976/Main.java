// 10976 Fractions Again?!
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1917
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
  class FA { // Fractions Again?!
    final static int MX = 100010000;
    FA() { }

    /*
      guessing where y will be for a given x and k is the key
      y = k*x/(x - k)
    */
    int get_ystart(int x, int k) {
      double fx = x;
      double fk = k;
      double yend = ((fk*fx)/(fx-fk));
      return (int) yend;
    }

    void solve(int k, int xa[], int ya[]) {
      int count = 0;
      int xstart = k+1;
      int xend = xstart * 2;

      /*
        Eliminate unnecessary iterations in the loops
      */
      for(int x = xstart; x <= xend; x++) {
        int ystart = get_ystart(x, k);
        int yend = ystart - 1;
        for(int y = ystart; y != yend; y--) {
          double fx = (double) x, fy = (double) y, fk = (double) k;
          if( (1/fk) == (fx+fy)/(fx*fy)) {
            if(y >= x) {
              xa[count] = x;
              ya[count] = y;
              count++;
            }
            ystart = get_ystart(x+1, k);
            break;
          }
        }
      }

      System.out.println(count);
      for(int i=0; i<count; i++) {
        System.out.println("1/"+k+" = 1/"+ya[i]+" + 1/"+xa[i]);
      }
    }
  }

  public static void main(String args[]) {
      int xa[] = new int[2000];
      int ya[] = new int[2000];

     Scanner sc = new Scanner(System.in);
     FA fa = new Main(). new FA();
     while(sc.hasNext()) {
       fa.solve(Integer.parseInt(sc.next()), xa, ya);
    }
  }
}
