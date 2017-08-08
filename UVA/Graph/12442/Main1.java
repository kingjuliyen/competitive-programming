// 12442 Forwarding Emails
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

class Main1 {

  class FE { // Forwarding Emails
    ArrayList< ArrayList<Integer> > paths;
    int NUM_NODES() { return 50000 + 8; }

    FE () {
      paths = new ArrayList < ArrayList<Integer> > (NUM_NODES());
      for(int i=0 ; i<NUM_NODES() - 3 ; i++) { paths.add(null); }
    }

    void addPath(int u, int v) {
      ArrayList<Integer> edges = paths.get(u); 
      if(edges == null) { 
        edges = new ArrayList<Integer> (); 
        paths.set(u, edges); 
      }
      edges.add(v);
    }

    int rcount; // reachability count
    boolean visitMap[];

    void resetVisitMap() { visitMap = new boolean[NUM_NODES()]; }
    boolean visited(int v) { return visitMap[v]; }
    void setVisited(int v) { visitMap[v] = true; }

    void R (int v ) { // v == vertex
      if(visited(v))
        return;
      setVisited(v);
      rcount++; 

      ArrayList<Integer> edges = paths.get(v);
      for(int i=0; i<edges.size(); i++) {
        int v1 = edges.get(i);
        R(v1);
      }
    }

    int prevRcount;
    int V;

    void updateResult(int v) {      
      if(rcount > prevRcount) {
        V = v;
        prevRcount = rcount;
      }
      else if (rcount == prevRcount && v < V) {
        V = v;
        prevRcount = rcount;
      }
    }

    void solve(int caseid) {
      prevRcount = -1;
      for(int i=0; i < NUM_NODES() - 5; i++) {
        if (paths.get(i) != null) {
          rcount = 0;
          resetVisitMap();
          R(i);
          updateResult(i);
        }
      }
      System.out.println("Case "+caseid+": "+V);
    }
  }

  public static void Main1(String s[]) {
    Scanner sc = new Scanner(System.in);
    int caseid = 1;
    while(sc.hasNext()) {
      int T = Integer.parseInt(sc.next());
      for(int t = 0; t < T; t++) {
        int N = Integer.parseInt(sc.next());
        FE fe = new Main1(). new FE();
        for(int n = 0; n < N; n++) {
          int u = Integer.parseInt(sc.next());
          int v = Integer.parseInt(sc.next());
          fe.addPath(u, v);
        }
        fe.solve(caseid++);
      }
    }
  }
}
