// 11581 - Grid Successors
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2628
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

  class GS {
    int ar[][];
    GS() {
      ar = new int[3][3];
    }
    int getInt(char c) {
      if(c=='0')
        return 0;
      else if(c=='1')
        return 1;
      return -1;
    }
    void addRow(int r, String s) {
      ar[r][0] = getInt(s.charAt(0));
      ar[r][1] = getInt(s.charAt(1));
      ar[r][2] = getInt(s.charAt(2));
    }

    boolean isTerminated() {
      return (ar[0][0] + ar[0][1] + ar[0][2] +
              ar[1][0] + ar[1][1] + ar[1][2] +
              ar[2][0] + ar[2][1] + ar[2][2]) == 0;
    }

    void fOfg() { // can write some loops too but hardcoding works for this problem
      int out[][] = new int[3][3];
      out[0][0] = ar[0][1] ^ ar[1][0]; // 01 10
      out[0][1] = ar[0][0] ^ ar[0][2] ^ ar[1][1]; // 00 02 11
      out[0][2] = ar[0][1] ^ ar[1][2];// 01 12

      out[1][0] = ar[0][0] ^ ar[2][0] ^ ar[1][1]; // 00 20 11
      out[1][1] = ar[0][1] ^ ar[2][1] ^ ar[1][0] ^ ar[1][2]; // 01 21 10 12
      out[1][2] = ar[0][2] ^ ar[2][2] ^ ar[1][1]; // 02 22 11

      out[2][0] = ar[1][0] ^ ar[2][1]; // 10 21
      out[2][1] = ar[2][0] ^ ar[2][2] ^ ar[1][1]; // 20 22 11
      out[2][2] = ar[1][2] ^ ar[2][1]; // 12 21

      for(int r=0; r<3; r++) {
        for(int c=0; c<3; c++) {
          ar[r][c] = out[r][c];
        }
      }
    }

    void solve() {
      int count = 0;
      while(!isTerminated()) {
        fOfg();
        count++;
      }
      count--;
      System.out.println(//"count "
                          +count);
    }
  } // class

    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int T = sc.nextInt();
      for(int i=0; i<T; i++){
        int count = 0;
        GS gs = new Main(). new GS();
        while(count<3) {
          String s = sc.next();
          gs.addRow(count, s);
          count++;
        }
        gs.solve();
      }
    }
}
