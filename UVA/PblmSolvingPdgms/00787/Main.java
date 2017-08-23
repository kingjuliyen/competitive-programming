// 787 - Maximum Sub-sequence Product
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=728
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
    class MSP { // Maximum Subsequence Product
      Vector <Integer> vi;
      MSP() { vi = new Vector <Integer>(); }
      void add(Integer x) { vi.add(x); }
      void solve() { }
    }
  
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      
      while(sc.hasNext()) {
        MSP msp = new Main(). new MSP();
        while(true) {
          int i = Integer.parseInt(sc.next());
          if(i == -999999) {
            break;
          }
          msp.add(i);
        }
        msp.solve();
      }

    }
}
