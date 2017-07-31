
// 11906 - Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3057
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

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
  vector<bool> spl; // search path list
  vector<Cell> wtrCl; // water cells

  KWG(int _R, int _C, int _M, int _N) : R(_R), 
  C(_C), M(_M), N(_N), x(0), y(0) { 
    spl = vector<bool>(R*C, false);
  }

  #define SPLVAL spl[(c.x * C + c.y)]
  bool isFoundInSearchPathListAlready(Cell &c) { return SPLVAL == true; }
  void addToSearchPathList(Cell &c) { SPLVAL = true; }
  void removeFromSearchPathList(Cell &c) { SPLVAL = false; }

  bool outOfBounds(Cell &c) {
    return (c.x >= 0 && c.x < C && c.y >=0 && c.y < R) ? false : true;
  }

  bool isMoveValid(Cell & s, Cell &d) {
    return (outOfBounds(d) || isWaterBlocked(s, d)) ? false : true;
  }

  bool isWaterBlocked(Cell &s, Cell &d) {
    int x0 = min(s.x, d.x), x1 = max(s.x, d.x);
    int y0 = min(s.y, d.y), y1 = max(s.y, d.y);

    for(auto i = wtrCl.begin(), e = wtrCl.end(); i != e; ++i) {
      int wx = i->x, wy = i->y;
      if( (wy == s.y && wx >= x0 && wx <= x1) ||
          (wx == d.x && wy >= y0 && wy <= y1) )
        return true;
    }
    return false;
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

  void dfs(Cell src) {
    if(isFoundInSearchPathListAlready(src))
      return;

    addToSearchPathList(src);
    {
      tryNextMove(src, src.x + M, src.y - N); // MHR_NVU,
      tryNextMove(src, src.x - M, src.y - N); // MHL_NVU,
      tryNextMove(src, src.x + M, src.y + N); // MHR_NVD,
      tryNextMove(src, src.x - M, src.y + N); // MHL_NVD, 

      tryNextMove(src, src.x + N, src.y - M); // NHR_MVU,
      tryNextMove(src, src.x - N, src.y - M); // NHL_MVU,
      tryNextMove(src, src.x + N, src.y + M); // NHR_MVD,
      tryNextMove(src, src.x - N, src.y + M); // NHL_MVD,
    }
    removeFromSearchPathList(src);
  }

  void markWaterSquare(int _x, int _y) { wtrCl.push_back(Cell(_x, _y)); }
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
    kwg.dfs(Cell(0,0));
  }
}
