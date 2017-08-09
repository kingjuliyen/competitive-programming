// 12442 Forwarding Emails
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;

class FE {
public:
  vector<int> paths;
  vector<bool> vstd;
  vector<int> mrc;
  int rcount, mdepth;
  int NUM_NODES() { return 50000 + 8; }
  int maxR;
  int V;

  FE() {
    paths = vector<int> (NUM_NODES(), -1);
    vstd = vector<bool> (NUM_NODES(), false);
    mrc = vector<int> (NUM_NODES(), -1);
  }

  void clearAll() {
    paths.assign(NUM_NODES()-1, -1);
    vstd.assign(NUM_NODES()-1, false);
    mrc.assign(NUM_NODES()-1, -1);
    V = maxR = -1;
    rcount = mdepth = 0;
  }

  int getConnection(int v) { return paths[v]; }
  void addPath(int u, int v) { paths[u] = v; }
  int getMaxReachable(int v) { return mrc[v]; }
  void setMaxReachable(int v, int r) { mrc[v] = r; }
  void clearAllVisited() { vstd.assign(NUM_NODES()-1, false); }
  void markAsVisited(int v) { vstd[v] = true; }
  bool visited(int v) { return vstd[v]; }
  void initForDfs() { clearAllVisited(); rcount = mdepth = 0;}

  void dfs(int v) {
    if(visited(v)) {
      mdepth = rcount;
      return;
    }
    markAsVisited(v);

    rcount++;
    int nv = getConnection(v);
    if(nv != -1)
      dfs(nv);
    setMaxReachable(v, mdepth - rcount);
    rcount--;
  }

  void checkAndsetMaxVals(int r, int v) {
    if(r > maxR) {
      maxR = r;
      V = v;
    }
  }

  void solve(int caseid) {
    for(int i=0; i<paths.size(); i++) {
      int e = getConnection(i);
      if(e == -1)
        continue;
      int r = getMaxReachable(i);
      if(r == -1) {
        initForDfs();
        dfs(i);
        r = getMaxReachable(i);
      }
      checkAndsetMaxVals(r, i);
    }
    cout << "Case " << caseid << ": " << V << endl;
  }
};

int main() {
  int T, N, caseId = 1, u, v;
  cin >> T;
  FE fe;
  while(T--)  {
    cin >> N;
    fe.clearAll();
    while(N--) {
      cin >> u >> v;
      fe.addPath(u, v);
    }
    fe.solve(caseId++);
  }
}

// Same solution when implemented in java gets TLE may be due to ArrayList

#if 0
// 12442 Forwarding Emails
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;
import java.lang.*;
import java.math.*;

class Main {
  class FE { // Forwarding Emails
    ArrayList<Integer> paths;
    ArrayList <Boolean> visited;
    ArrayList<Integer> mrc; // max reachability cache
    int rcount, mdepth;
    int NUM_NODES() { return 50000 + 8; }
    int maxR; // max Reachable vertexes during dfs
    int V;    // vertex from which max vertexes can be reached

    FE () {
      paths = new ArrayList<Integer> (NUM_NODES());
      visited = new ArrayList<Boolean> (NUM_NODES());
      mrc = new ArrayList<Integer> (NUM_NODES());
      for(int i=0 ; i<NUM_NODES() - 3; i++) { paths.add(-1); }
      for(int i=0 ; i<NUM_NODES() - 3 ; i++) { visited.add(false); }
      for(int i=0 ; i<NUM_NODES() - 3 ; i++) { mrc.add(-1); }
    }

    void clearAll() {
      for(int i=0 ; i<NUM_NODES() - 3; i++) { paths.set(i, -1); }
      for(int i=0 ; i<NUM_NODES() - 3 ; i++) { visited.set(i, false); }
      for(int i=0 ; i<NUM_NODES() - 3 ; i++) { mrc.set(i, -1); }
      V = maxR = -1;
      rcount = mdepth = 0;
    }

    int getConnection(int v) { return paths.get(v); }
    void addPath(int u, int v) { paths.set(u, v); }
    int getMaxReachable(int v) { return mrc.get(v); }
    void setMaxReachable(int v, int r) { mrc.set(v, r); }
    void clearAllVisited() { for(int i=0 ; i<NUM_NODES()-3; i++) { visited.set(i, false); } }
    void markAsVisited(int v) { visited.set(v, true); }
    boolean visited(int v) { return visited.get(v); }
    void initForDfs() { clearAllVisited(); rcount = mdepth = 0;}

    void dfs(int v) {
      // System.out.println("dfs v "+v);
      if(visited(v)) {
        mdepth = rcount;
        return;
      }
      markAsVisited(v);

      rcount++;
      int nv = getConnection(v);
      if(nv != -1)
        dfs(nv);
      setMaxReachable(v, mdepth - rcount);
      rcount--;
    }

    void checkAndsetMaxVals(int r, int v) {
      if(r > maxR) {
        maxR = r;
        V = v;
      }
    }

    void solve(int caseid) {
      for(int i=0; i<paths.size(); i++) {
        int e = getConnection(i);
        if(e == -1)
          continue;
        // System.out.println("****** solve i "+i);
        int r = getMaxReachable(i);
        if(r == -1) {
          initForDfs();
          dfs(i);
          r = getMaxReachable(i);
        }
        checkAndsetMaxVals(r, i);
      }
      System.out.println("Case "+caseid+": "+V);
    }
  }

  public static void main(String s[]) {
    Scanner sc = new Scanner(System.in);
    int caseid = 1;
    FE fe = new Main(). new FE();
    while(sc.hasNext()) {
      int T = Integer.parseInt(sc.next());
      for(int t = 0; t < T; t++) {
        int N = Integer.parseInt(sc.next());      
        fe.clearAll();
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
#endif
