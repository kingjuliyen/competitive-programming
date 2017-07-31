
// 11906 - Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3057
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
using namespace std;

struct Cell {
  int x, y;
  Cell(int _x, int _y): x(_x), y(_y) { }
  static Cell BADCELL (); // { return Cell(-5, -5); }
  bool isValid() { return !(x == -5 && y == -5); }
};
Cell Cell::BADCELL () { return Cell(-5, -5); }

class KWG { // Knight War Grid
public:
  int R, C, M, N, x, y;
  KWG(int _R, int _C, int _M, int _N) : R(_R), 
  C(_C), M(_M), N(_N), x(0), y(0) { }

  bool outOfBounds(Cell &c) {
    return (c.x >= 0 && c.x < C && c.y >=0 && c.y < R) ? true : false;
  }

  bool isMoveValid(Cell & s, Cell &d) {
    return (outOfBounds(d) || isWaterBlocked(s, d)) ? false : true;
  }

  bool isWaterBlocked(Cell &s, Cell &d) {
    return false;
  }

  bool isFoundInSearchPathListAlready(Cell &src) {
    return false;
  }

  void addToSearchPathList(Cell &c) {
  }

  void removeFromSearchPathList(Cell &c) {
  }
  
  void updateReachability(Cell &d, Cell &s) {
  }

#define tryNextMove(s, dx, dy) \
  do { \
    Cell d = Cell(dx, dy); \
    if(isMoveValid(s, d)) { \
        updateReachability(d, s); /* dst can be reached from src */ \
        dfs(d); \
    } \
  } while(0)

  void dfs(Cell cur) {
    if(isFoundInSearchPathListAlready(cur))
      return;

    addToSearchPathList(cur);
    {
      tryNextMove(cur, cur.x + M, cur.y - N); // MHR_NVU,
      tryNextMove(cur, cur.x - M, cur.y - N); // MHL_NVU,
      tryNextMove(cur, cur.x + M, cur.y + N); // MHR_NVD,
      tryNextMove(cur, cur.x - M, cur.y + N); // MHL_NVD, 

      tryNextMove(cur, cur.x + N, cur.y - M); // NHR_MVU,
      tryNextMove(cur, cur.x - N, cur.y - M); // NHL_MVU,
      tryNextMove(cur, cur.x + N, cur.y + M); // NHR_MVD,
      tryNextMove(cur, cur.x - N, cur.y + M); // NHL_MVD,
    }
    removeFromSearchPathList(cur);
  }

  void markWaterSquare(int _x, int _y) {

  }

  void solve() {
    dfs(Cell(0,0));
  }
};

int main() {
  int T = -1;
  cin >> T;
  while(T--) {
    int R = -1, C = -1, M = -1, N = -1, W = -1, x = -1, y = -1;
    cin >> R >> C >> M >> N;    
    cin >> W;
    cout << " R " << R << " C " << C << " M " << " N " << N << " W " << W << "\n" ;
    KWG kwg(R, C, M, N);
    while(W--) {
      cin >> x >> y;
      cout << " x " << x << " y " << y << "\n";
      kwg.markWaterSquare(x, y);
    }
    kwg.solve();
  }
}
