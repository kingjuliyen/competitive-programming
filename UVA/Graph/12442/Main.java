// 12442 Forwarding Emails
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

class Main {

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

    void dfs(int v) {
      if(visited(v))
        return;
      setVisited(v);
      rcount++; 

      ArrayList<Integer> edges = paths.get(v);
      if(edges == null) {
        rcount = 0;
        return;
      }
      for(int i=0; i<edges.size(); i++) {
        int v1 = edges.get(i);
        dfs(v1);
      }
    }

    int chdR[];
    void initCachedR() {
      chdR = new int[NUM_NODES()]; 
      for(int i=0; i<NUM_NODES(); i++) { chdR[i] = -1; }
    }
    void setCachedR(int v, int r) { chdR[v] = r; }
    int cachedR(int v) { return chdR[v]; }

    // reScore - reachability scores for each vertex
    int maxR(ArrayList<Integer> reScore) {
      if(reScore.size() == 0)
        return 0;
      Collections.sort(reScore);
      return reScore.get(reScore.size() - 1);
    }

    boolean vMap2[]; // visit Map
    void resetVMp2() { vMap2 = new boolean[NUM_NODES()]; }
    boolean visitedVMp2(int v) { return vMap2[v]; }
    void setVisitedVMp2(int v) { vMap2[v] = true; }

    int R (int v ) { // v == vertex
      int cr = cachedR(v);
      if( cr != -1) {
        return cr;
      }

      if(visitedVMp2(v)) {
        return -500000000;
      }
      setVisitedVMp2(v);

      ArrayList<Integer> edges = paths.get(v);
      if(edges == null) {
        setCachedR(v, 0);
        return 0;
      }

      ArrayList<Integer> re_ai = new ArrayList<Integer>(edges.size());

      for(int i=0; i<edges.size(); i++) {
        int v1 = edges.get(i) , r = -1;
        if(visitedVMp2(v1)) {
          resetVisitMap();
          dfs(v1);
          r = rcount;
          setCachedR(v1, r);
        } else {
          r = R(v1);
        }

        int cr2 = cachedR(v);
        if( cr2 != -1) {
          return cr2;
        }

        r += 1;
        re_ai.add(r);
      }
      int mr = maxR(re_ai);
      setCachedR(v, mr);
      return mr;
    }

    int getResult() {
      int prc = -1 , pv = -1;
      System.out.println(" getResult ");
      for(int i=0; i< chdR.length; i++) {
        int r = chdR[i];
        if(r == -1)
          continue;
        System.out.println(" v "+i+" r "+r);
        if(r > prc) {
          prc = r;
          pv = i;
        }
      }
      return pv;
    }

    void solve(int caseid) {
      initCachedR();
      for(int i=0; i < NUM_NODES() - 5; i++) {
        if (paths.get(i) != null) {
          resetVMp2();
          R(i);
        }
      }
      System.out.println("Case "+caseid+": "+getResult());
    }
  }

  public static void main(String s[]) {
    Scanner sc = new Scanner(System.in);
    int caseid = 1;
    while(sc.hasNext()) {
      int T = Integer.parseInt(sc.next());
      for(int t = 0; t < T; t++) {
        int N = Integer.parseInt(sc.next());
        FE fe = new Main(). new FE();
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
