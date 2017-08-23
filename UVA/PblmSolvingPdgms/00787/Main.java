// 787 - Maximum Sub-sequence Product
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=728
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
    class MSP { // Maximum Subsequence Product
      Vector <BigInteger> vi; int R, C; BigInteger max; BigInteger[][] mtx; // matrix
      MSP() { vi = new Vector <BigInteger>(); max = new BigInteger(Integer.toString(-999999)); }
      void add(BigInteger x) { vi.add(x); }
      
      void setVal(int r, int c, BigInteger bi) {
        mtx[r][c] = bi;
        max = max.max(bi);
      }
      
      void solve() {
        if(vi.size() ==1) {
          System.out.println(vi.get(0).toString());
          return;
        }
        
        R = C = vi.size(); R--;
        mtx = new BigInteger[R][C];
        for(int r= R-1; r>=0; r--) {
          for(int c = C-1; c>=0; c--) {
            if(c == r+1) {
              setVal(r,c, vi.get(r).multiply(vi.get(c)));
              break;
            }
            setVal(r,c, vi.get(r).multiply(mtx[r+1][c]));
          }
        }
        System.out.println(max.toString());
      } // void solve()

    } // class MSP 
  
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      
      while(sc.hasNext()) {
        MSP msp = new Main(). new MSP();
        while(true) {
          int i = Integer.parseInt(sc.next());
          if(i == -999999) {
            break;
          }
          msp.add(new BigInteger(Integer.toString(i)));
        }
        msp.solve();
      }

    }
}
