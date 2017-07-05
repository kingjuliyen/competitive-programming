// 10443 - Rock
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1384
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

  class RPS {
    int row;
    int col;
    int days;
    char matrix[];
    int limit;

    RPS(int r, int c, int n) {
      row = r;
      col = c;
      days = n;
      matrix = new char[r*c];
      limit = r*c;
    }

    void set(int r, int c, char val) {
      if(r < 0 || r >= row ||
         c < 0 || c >= col)
         return;
      matrix[(r*col) + c] = val;
    }

    char get(int r, int c) {
      if(r < 0 || r >= row ||
         c < 0 || c >= col)
         return 'z';
      return matrix[(r*col) + c];
    }

    void addRow(String s, int r) {
      for(int c=0; c<col;c++) {
        set(r,c, s.charAt(c));
      }
    }

    void print() {
      for(int r=0; r<row; r++) {
        StringBuffer sb = new StringBuffer();
        for(int c=0; c<col; c++) {
          sb.append(get(r,c));
        }
        System.out.println(sb);
      }
    }

    char getKiller(char c) {
      switch(c) {
        case 'P':
        return 'S';

        case 'R':
        return 'P';

        case 'S':
        return 'R';
      }
      return 'y';
    }

    boolean checkForKiller(int r, int c, int r2, int c2) {
      int offet = (r*col) + c;
      char current = get(r,c);
      char killer = get(r2,c2);
      if(current =='z' || killer == 'z')
        return false;
      if(killer == getKiller(current))
        return true;
      return false;
    }

    boolean checkUpperCell(int r, int c) {
      return checkForKiller(r,c, r-1, c);
    }

    boolean checkRightCell(int r, int c) {
      return checkForKiller(r,c, r, c+1);
    }

    boolean checkDownCell(int r, int c) {
      return checkForKiller(r,c, r+1, c);
    }

    boolean checkLeftCell(int r, int c) {
      return checkForKiller(r,c, r, c-1);
    }

    void check_and_replace( ) {
      boolean bm[] = new boolean[limit]; // boolean for matrix bitmap
      for(int k=0; k<limit; k++) { bm[k] = false; }

      for(int r=0; r<row; r++) {
        for(int c=0; c<col; c++) {

          if(checkUpperCell(r,c) || checkRightCell(r,c) ||
              checkDownCell(r,c) || checkLeftCell(r,c))
             bm[(r*col) + c] = true;
        }
      }

      for(int r=0; r<row; r++) {
        for(int c=0; c<col; c++) {
          boolean b = bm[(r*col)+c];
          if(b) {
            char c0 = get(r, c);
            set(r,c, getKiller(c0));
          }
        }
      }
    }

    void solve() {
      for(int i=1; i<=days;i++) {
        check_and_replace();
      }
    }

  } // class RPS

  public static void main(String s[]) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();

    for(int i=1; i<=t; i++) {
      int r = sc.nextInt();
      int c = sc.nextInt();
      int n = sc.nextInt();

      RPS rps = new Main().new RPS(r,c,n);
      for(int j=0; j<r; j++) {
         String rd = sc.next();
         rps.addRow(rd, j);
      }
      rps.solve();
      rps.print();
      if(i<t) {
        System.out.println("");
      }
    }

  }
}
