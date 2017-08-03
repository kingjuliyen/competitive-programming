
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
  vector<int> deltas;
  map< pair<int, int>, bool > vst;
  map< pair<int, int>, bool > waterMap;

  KWG(int _R, int _C, int _M, int _N) : R(_R),
    C(_C), M(_M), N(_N), odds(0), evens(0) 
  {
      if(M != N)
        deltas = {  M, -N,    M, N,   -M, N,    -M, -N,
                  N, -M,    N, M,   -N, M,    -N, -M };
      else
        deltas = {  M, -N,    M, N,   -M, N,    -M, -N };
  }

  void markWaterSquare(int x, int y) { 
    waterMap[make_pair(x,y)] = true;
  }

  bool waterSquare(int x, int y) {
    auto it = waterMap.find(make_pair(x,y));
    return (it == waterMap.end()) ? false : it->second;
  }

  bool validSquare(int x, int y) { 
    //cout << " C " << C << " R " << R << " x " << x << " y " << y << endl;
    return (x>=0 && x<R && y>=0 && y<C);
    // return (x>=0 && x<C && y>=0 && y<R); 
  }
  int getAsOffset(int x, int y) { return (x * C + y); }
  int getAsOffset2(int x, int y) { return (y * C + x); }

  void markVisited(int x, int y) {
    vst[make_pair(x,y)] = true;
  }

  bool visited(int x, int y) {
    auto it = vst.find(make_pair(x,y));
    return (it == vst.end()) ? false : it->second;
  }

  typedef pair<int, int> point;
  typedef pair <point, point> dst_src_pair;
  map<dst_src_pair, bool> uniqPath;
  map <point, int> pthCount;

  void incrPathCount(point d, point s) {
    dst_src_pair dsp = make_pair(d,s);
    auto it = uniqPath.find(dsp);
    if(it == uniqPath.end()) {
      uniqPath[dsp] = true;
      auto it2 = pthCount.find(d);
      if(it2 == pthCount.end()) {
        pthCount[d] = 1;
      }
      else {
        pthCount[d] = pthCount[d] + 1;
      }
    }
  }

  bool okForNextJump(int x, int y) {
    if(!validSquare(x, y))
      return false;
    if(waterSquare(x, y))
      return false;
    return true;  
  }

  void dfs(int x, int y) {
    if(visited(x,y))
      return;  
    markVisited(x, y);

    for(int i=0; i<deltas.size()/2; i++) {
      int x1 = x + deltas[i*2];
      int y1 = y + deltas[(i*2)+1];
      // if(x == 16 && y == 10)
      //   printf("src %d,%d    dst %d,%d\n", x, y, x1, y1);

      if(!okForNextJump(x1, y1))
        continue;
      // printf("**src=%d,%d    **dst=%d,%d\n", x, y, x1, y1);
      incrPathCount(make_pair(x1, y1),  make_pair(x, y));
      dfs(x1, y1);
    }
  }
  
  void printStats(int caseId) {
    int odds = 0, evens = 0;
    for(auto i= pthCount.begin(), e = pthCount.end(); i!=e; ++i) {
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
    // cout << "caseid " << (caseId+1) << endl;
    // cout << R << " " << C << " " << M << " " << N << endl;
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
