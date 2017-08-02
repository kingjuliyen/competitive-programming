
// 11906 - Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3057
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;

struct Cell {
  int x, y;
  Cell(int _x, int _y) : x(_x), y(_y) {}
  void print() { cout << " x " << x << " y " << y << "\n"; }
};

enum MOV_SEQ { HOR_VER = 0x53, VER_HOR };

class KWG
{ // Knight War Grid
public:
  int R, C, M, N, x, y;
  vector<bool> spl;   // search path list
  vector<Cell> wtrCl; // water cells
  vector <vector<int> *> dstMap;

  KWG(int _R, int _C, int _M, int _N) : R(_R),
    C(_C), M(_M), N(_N), x(0), y(0) {
    int T = R * C;
    spl = vector<bool>(T, false);
    dstMap = vector <vector<int> *> (T);
    for (int i = 0; i < T; i++) {
      dstMap[i] = new vector<int> (T, 0);
    }
  }

  #define SPLVAL spl[(c.x * C + c.y)]
  bool isFoundInSearchPathListAlready(Cell &c) { return SPLVAL == true; }
  void addToSearchPathList(Cell &c) { SPLVAL = true; }
  void removeFromSearchPathList(Cell &c) { SPLVAL = false; } 
  void updateReachability(Cell &d, Cell &s) {
  }

  #define BAD_VAL (-500)
  Cell BAD_CELL() { return Cell(BAD_VAL, BAD_VAL); }
  void SET_CELL(Cell &orig, Cell &tmp) { tmp.x = orig.x;  tmp.y = orig.y; }
  void SET_CELL_BAD(Cell &c) { c.x = BAD_VAL; c.y = BAD_VAL; }
  bool IS_BAD_CELL(Cell &c) { 
    cout << " IS_BAD_CELL\n ";
    c.print();
    return (c.x == BAD_VAL && c.y == BAD_VAL); 
  }

  bool cell_range_ok(Cell &c)  {
    return (c.x >= 0 && c.x < C) && (c.y >= 0 && c.y < R);
  }

  bool water_in_path_hv(Cell &c1, Cell &c2, Cell &c3)
  {
    for (auto i = wtrCl.begin(), e = wtrCl.end(); i != e; ++i) {
      int wx = i->x, wy = i->y;
      int x1 = min(c1.x, c2.x), x2 = max(c1.x, c2.x), y = c1.y;
      bool b1 = (wy == y && wx >= x1 && wx <= x2);
      if (b1) {
        cout << "water_in_path_hv (wy == y && wx >= x1 && wx <= x2)\n";
        return true;
      }

      int y1 = min(c2.y, c3.y), y2 = max(c2.y, c3.y), x = c3.x;
      bool b2 = (wx == x && wy >= y1 && wy <= y2);
      if (b2) {
        cout << "water_in_path_hv (wx == x && wy >= y1 && wy <= y2)\n";
        return true;
      }
    }
    cout << "water_in_path_hv false\n";
    return false;
  }

    bool water_in_path_vh(Cell &c1, Cell &c2, Cell &c3) {
      for (auto i = wtrCl.begin(), e = wtrCl.end(); i != e; ++i) {
        int wx = i->x, wy = i->y;

        int y1 = min(c1.y, c2.y), y2 = max(c1.y, c2.y), x = c1.x;
        bool b1 = (wx == x && wy >= y1 && wy <= y2);
        if (b1) {
          cout << "water_in_path_vh (wx == x && wy >= y1 && wy <= y2)\n";
          return true;
       }

        int x1 = min(c2.x, c3.x), x2 = max(c2.x, c3.x), y = c3.y;
        bool b2 = (wy == y && wx >= x1 && wx <= x2);
        if (b2) {
          cout << "water_in_path_vh (wy == y && wx >= x1 && wx <= x2)";
          return true;
        }
      }
      cout << "water_in_path_vh false\n";
      return false;
    }

  bool water_in_path(Cell &c1, Cell &c2, Cell &c3, MOV_SEQ sq)
  {
    return (sq == HOR_VER) ? water_in_path_hv(c1, c2, c3) : water_in_path_vh(c1, c2, c3);
  }

  void next_mov(Cell &s, Cell &range_end, Cell &d, Cell &out, MOV_SEQ sq)  {
    if (!cell_range_ok(s) || !cell_range_ok(range_end) || !cell_range_ok(d)) {
      cout << "!cell_range_ok(s) || !cell_range_ok(range_end) || !cell_range_ok(d)\n";
      SET_CELL_BAD(out);
      out.print();
      return;
    }

    if (water_in_path(s, range_end, d, sq)) {
      SET_CELL_BAD(out);
      return;
    }
    SET_CELL(d, out);
  }

  #define OFST(k) (k.x * C + k.y)
  #define OFST2(x0, y0) (x0 * C + y0)

  void printPathToDst(int di) {
    vector<int> * sbv = dstMap[di];
    for(int i=0; i<(R*C); i++) {
      int v = sbv->at(i);
      cout << " dst " << di << " <- src " << i << " " << v << "\n";
    }
    cout << "\n";
  }

  void printStats() {
    for (int d = 0; d<(R*C); d++) {
      printPathToDst(d);
    }
  }
  void setPathMarked(Cell &d, Cell &s) {
    int svi = OFST(d);
    vector<int> * sbv = dstMap[svi];
    int smi = OFST(s);
    sbv->at(smi) = sbv->at(smi) + 1;
  }

  void recordPathBetween(Cell &d, Cell &s) {
    setPathMarked(d, s);
    setPathMarked(s, d);
  }

  bool pathFoundBetween(Cell &d, Cell &s) {
    int svi = OFST(d);
    cout << " svi " << svi << "\n";
    vector<int> * sbv = dstMap[svi];
    int smi = OFST(s);
    cout << " sbv " << sbv << "\n";
    int v = sbv->at(smi);
    bool b = (v > 0);
    return b;
    //return false;
  }

  #define TRY_MOVE(dx1, dy1, dx2, dy2, dir, dbgstr) \
    do { \
      cout << "\n\n TRY_MOVE src "; src.print(); \
      if (isFoundInSearchPathListAlready(src)) { \
        cout << " isFoundInSearchPathListAlready(src) \n"; \
        break; \
      } \
      addToSearchPathList(src); \
      cout << " TRY_MOVE " << dbgstr << "\n"; \
      Cell out = BAD_CELL(); \
      Cell tmp(src.x + dx1, src.y + dy1); Cell dst(tmp.x + dx2, tmp.y + dy2); \
      if (!cell_range_ok(src) || !cell_range_ok(dst)) { \
        removeFromSearchPathList(src); \
        break; \
      } \
      if(pathFoundBetween(dst, src)) { \
        removeFromSearchPathList(src); \
        break; \
      } \
      cout << " src "; src.print(); \
      cout << " pivot "; tmp.print(); \
      cout << " dst "; dst.print(); \
      next_mov(src, tmp, dst, out, dir); \
      if(!IS_BAD_CELL(out)) { \
        recordPathBetween(dst, src); \
        cout << " ##############  VALID PATH ##############  \n"; \
        dfs(dst); \
      } \
      removeFromSearchPathList(src); \
    } while(0)

  void dfs(Cell src) {
    // if (isFoundInSearchPathListAlready(src))
    //   return;

    TRY_MOVE( M, 0, 0, -N, HOR_VER, "MN hor right, ver up");
    TRY_MOVE( M, 0, 0,  N, HOR_VER, "MN hor right, ver down");
    TRY_MOVE(-M, 0, 0, -N, HOR_VER, "MN hor left, ver up");
    TRY_MOVE(-M, 0, 0,  N, HOR_VER, "MN hor left, ver down");

    TRY_MOVE(0, -N,  M, 0, VER_HOR, "MN ver up hor right, ");
    TRY_MOVE(0,  N,  M, 0, VER_HOR, "MN ver down hor right, ");
    TRY_MOVE(0, -N, -M, 0, VER_HOR, "MN ver up hor left, ");
    TRY_MOVE(0,  N, -M, 0, VER_HOR, "MN ver down hor left, ");

    TRY_MOVE(0,  M,  N, 0, VER_HOR, "NM ver down, hor right");
    TRY_MOVE(0,  M, -N, 0, VER_HOR, "NM ver down, hor left");
    TRY_MOVE(0, -M,  N, 0, VER_HOR, "NM ver up, hor right");
    TRY_MOVE(0, -M, -N, 0, VER_HOR, "NM ver up, hor left");

    TRY_MOVE(N,  0,  0, M, HOR_VER, "NM hor right ver down, ");
    TRY_MOVE(-N,  0, 0, M, HOR_VER, "NM hor left ver down, ");
    TRY_MOVE(N, 0,  0, -M, HOR_VER, "NM hor right ver up, ");
    TRY_MOVE(-N, 0, 0, -M, HOR_VER, "NM hor left ver up, ");
    


    // addToSearchPathList(src);
    // removeFromSearchPathList(src);// s == source
  }

  void markWaterSquare(int _x, int _y) { wtrCl.push_back(Cell(_x, _y)); }
};

int main()
{
  int T = -1;
  cin >> T;
  while (T--)
  {
    int R = -1, C = -1, M = -1, N = -1, W = -1, x = -1, y = -1;
    cin >> R >> C >> M >> N;
    cin >> W;
    cout << " R " << R << " C " << C << " M " << M << " N " << N << " W " << W << "\n";
    KWG kwg(R, C, M, N);
    while (W--)
    {
      cin >> x >> y;
      cout << " x " << x << " y " << y << "\n";
      kwg.markWaterSquare(x, y);
    }
    kwg.dfs(Cell(0, 0));
    kwg.printStats();
  }
}
