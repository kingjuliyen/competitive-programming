// 10855 - Rotated square
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=20&page=show_problem&problem=1796
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {
  class RS {
    int N, n, bigMat[], smMat[];

    RS (int _N, int _n){
      N = _N;
      n = _n;
      bigMat = new int[N*N];
      smMat = new int[n*n];
    }

    void set(int ar[], int dim, int r, int c, char v) {
      if(r<0||r>=dim || c<0 || c>=dim)
        return;
      ar[(r*dim)+c] = v;
    }

    void addRow(int ar[], int dim, String s, int row) {
      int x = 0;
      for(int c=0; c<dim; c++){
        set(ar, dim, row, c, s.charAt(x));
        x++;
      }
    }

    int[] rotate90(int in[], int dim) {
      int out[] = new int[dim*dim];
      int x = 0;
      for(int c=dim-1; c>=0; c--) {
        for(int r=0; r<dim; r++) {
          char ch = (char) in[x];
          out[(r*dim) + c] = in[x++];
        }
      }
      return out;
    }

    char get(int ar[], int dim, int r, int c) {
      if(r>=dim || c>=dim)
        return (char) -1;
      return (char) ar[(r*dim)+c];
    }

    boolean check(int b[], int r, int c, int s[]) {
      for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
          char sc = get(s,n, row,col);
          char bc = get(b,N, (r+row), (c+col));
          if(sc == -1 || bc == -1 || sc != bc) {
            return false;
          }
        }
      }
      return true;
    }

    int solve(int b[], int s[]) {
      int count = 0;
      for(int r=0; r<N;r++) {
        for(int c=0; c<N; c++) {
          boolean rb = check(b,r,c, s);
          if(rb)
            count++;
        }
      }
      return count;
    }

    void solve() {
      int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
      c1 = solve(bigMat, smMat);

      int mat90[] = rotate90(smMat, n);
      c2 = solve(bigMat, mat90);

      int mat180[] = rotate90(mat90, n);
      c3 = solve(bigMat, mat180);

      int mat270[] = rotate90(mat180, n);
      c4 = solve(bigMat, mat270);

      System.out.println(c1+" "+c2+" "+c3+" "+c4);
    }

  } // class RS

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int count = 1;
    while(true){
      int N = sc.nextInt();
      int n = sc.nextInt();
      if(N==0 && n==0)
        break;

      RS rs = new Main(). new RS(N, n);
      for(int i=0; i<N; i++) {
        String s = sc.next();
        rs.addRow(rs.bigMat, N, s, i);
      }
      for(int i=0; i<n; i++) {
        String s = sc.next();
        rs.addRow(rs.smMat, n, s, i);
      }
      rs.solve();
    }
  }
}
