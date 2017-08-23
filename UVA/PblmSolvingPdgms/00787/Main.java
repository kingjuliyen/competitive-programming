// 787 - Maximum Sub-sequence Product
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=728
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*; import java.lang.*; import java.math.*;
/*
  Refer to howto.png, there is some dp pattern, note single number by itself is a sequence
*/

public class Main {
    class MSP { // Maximum Subsequence Product
      Vector <BigInteger> vi; int R, C; BigInteger high; BigInteger[][] mtx; // matrix
      MSP() { vi = new Vector <BigInteger>(); high = new BigInteger(Integer.toString(-999999)); }
      void add(BigInteger x) { vi.add(x); }
      void setVal(int r, int c, BigInteger bi) { mtx[r][c] = bi; high = high.max(bi); }
      
      void solve() {
        R = C = vi.size(); mtx = new BigInteger[R][R];
        for(int r= R-2; r>=0; r--)
          for(int c = C-1; c>=0; c--) {
            if(c == r+1) {
              setVal(r,c, vi.get(r).multiply(vi.get(c)));
              break;
            }
            setVal(r,c, vi.get(r).multiply(mtx[r+1][c]));
          }
        for(int c=0; c<R; c++) { setVal(R-1, c, vi.get(c)); } // single number by itself is a sequence
        System.out.println(high.toString());
      } // void solve()
    } // class MSP

    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      while(sc.hasNext()) {
        MSP msp = new Main(). new MSP();
        while(true) {
          int i = Integer.parseInt(sc.next());
          if(i == -999999)
            break;
          msp.add(new BigInteger(Integer.toString(i)));
        }
        msp.solve();
      }
    } // public static void main(String args[])
}
