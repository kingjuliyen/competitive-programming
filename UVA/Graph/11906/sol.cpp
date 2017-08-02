
// 11906 - Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3057
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class KWG
{ // Knight War Grid
public:
  int R, C, M, N, odds, evens;
  map < pair<int, int>, bool> waterMap;
  vector<int> deltas;
  map< pair<int, int>, bool > pathMap;
  map<int, bool> vst;
  map<int, int> pathCount;

  KWG(int _R, int _C, int _M, int _N) : R(_R),
    C(_C), M(_M), N(_N), odds(0), evens(0) {
      if(M != N)
        deltas = {  M, -N,    M, N,   -M, N,    -M, -N,
                  N, -M,    N, M,   -N, M,    -N, -M };
      else
        deltas = {  M, -N,    M, N,   -M, N,    -M, -N };
        pathCount.clear();
        //pathCount = vector<int>(R*C, 0);
     }

  void markWaterSquare(int x, int y) { waterMap[make_pair(x, y)] = true; }
  bool waterSquare(pair<int, int> s) { return waterMap.find(s) != waterMap.end(); }
  bool validSquare(int x, int y) { return (x>=0 && x<C && y>=0 && y <R); }
  int getAsOffset(int x, int y) { return (x * C + y); }

  void markVisited(int x, int y) { vst[(getAsOffset(x, y))] = true; }
  bool visited(int x, int y) {
    return (vst.find(getAsOffset(x, y))   != vst.end()); 
  }
  void unmarkVisited(int x, int y) { vst.erase(getAsOffset(x, y)); }

  bool markPathBetween(int dx, int dy, int sx, int sy) {
    int d = getAsOffset(dx, dy), s = getAsOffset(sx, sy);
    if(pathMap.find(make_pair(d,s)) != pathMap.end())
      return true;
    pathMap[make_pair(d,s)] = true;

    if(pathCount.find(d) == pathCount.end()) {
      pathCount[d] = 1;
    }
    else {
      pathCount[d] = pathCount[d] + 1;
    }
    return false;
  }

  bool okForNextJump(int x, int y) {
    if(!validSquare(x, y))
      return false;
    if(waterSquare(make_pair(x, y)))
      return false;
    return true;
  }

  void dfs(int x, int y) {
    // cout << "src " << x << "," << y << endl; 
    markVisited(x, y);

    for(int i=0; i<deltas.size()/2; i++) {
      int x1 = x + deltas[i*2]; 
      int y1 = y + deltas[(i*2)+1];

      // cout << " x1 " << x1 << " y1 " << y1 << endl;
      if(!okForNextJump(x1, y1))
        continue;
      
      bool pathAlreadyMarked = markPathBetween(x1, y1, x, y);
      // cout << "bool pathAlreadyMarked = markPathBetween(x1, y1, x, y); \n";

      if(!pathAlreadyMarked && !visited(x1,y1)) {
        // cout << "!pathAlreadyMarked && !visited(x1,y1) \n";
        dfs(x1, y1);
      }
    }
  
    // cout << "unmarkVisited(x, y); \n";
    unmarkVisited(x, y);
    // cout << "after unmarkVisited(x, y); \n";
  }
  
  void printStats(int caseId) {
    int odds = 0, evens = 0;
    for(auto i= pathCount.begin(), e = pathCount.end(); i!=e; ++i) {
      int v = i->second;
      if(v & 0x01)
        odds += 1;
      else
        evens += 1;
    }
    // cout << " evens " << evens << " odds " << odds << endl;
    if(!odds && !evens)
    evens = 1;
    cout << "Case " << caseId << ":" << " " << evens << " " << odds << "\n";
  }

  void solve(int caseId) {
    dfs(0, 0);
    printStats(caseId);
  }
}; // class KWG

int main()
{
  int T = -1, caseId = 0;
  cin >> T;
  while (T--)
  {
    int R = -1, C = -1, M = -1, N = -1, W = -1, x = -1, y = -1;
    cin >> R >> C >> M >> N;
    cin >> W;
    KWG kwg(R, C, M, N);
    while (W--)
    {
      cin >> x >> y;
      kwg.markWaterSquare(x, y);
    }
    kwg.solve(++caseId);
  }
}
