
// 11906 - Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3057
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;
#define OFST(k) (k.x * C + k.y)
#define OFST2(x0, y0) (x0 * C + y0)
#define BAD_VAL (-500)
#define SPLVAL spl[(c.x * C + c.y)]

struct Cell {
  int x, y;
  Cell(int _x, int _y) : x(_x), y(_y) {}
};
Cell BAD_CELL() { return Cell(BAD_VAL, BAD_VAL); }
void SET_CELL(Cell &orig, Cell &tmp) { tmp.x = orig.x;  tmp.y = orig.y; }
void SET_CELL_BAD(Cell &c) { c.x = BAD_VAL; c.y = BAD_VAL; }
bool IS_BAD_CELL(Cell &c) { return (c.x == BAD_VAL && c.y == BAD_VAL); }

enum MOV_SEQ { HOR_VER = 0x53, VER_HOR };

class KWG
{ // Knight War Grid
public:
  int R, C, M, N, odds, evens;
  vector<bool> spl;   // search path list
  vector<Cell> wtrCl; // water cells
  vector <vector<int> *> dstMap;

  KWG(int _R, int _C, int _M, int _N) : R(_R),
    C(_C), M(_M), N(_N), odds(0), evens(0) {
    int T = R * C;
    spl = vector<bool>(T, false);
    dstMap = vector <vector<int> *> (T);
    for (int i = 0; i < T; i++) {
      dstMap[i] = new vector<int> (T, 0);
    }
  }

  void markWaterSquare(int _x, int _y) { wtrCl.push_back(Cell(_x, _y)); } 
  bool isFoundInSearchPathListAlready(Cell &c) { return SPLVAL == true; }
  void addToSearchPathList(Cell &c) { SPLVAL = true; }
  void removeFromSearchPathList(Cell &c) { SPLVAL = false; }
  bool cell_range_ok(Cell &c)  {  return (c.x >= 0 && c.x < C) && (c.y >= 0 && c.y < R); }

  bool water_in_path_hv(Cell &c1, Cell &c2, Cell &c3)
  {
    for (auto i = wtrCl.begin(), e = wtrCl.end(); i != e; ++i) {
      int wx = i->x, wy = i->y;
      if( (wy == c1.y && wx >= min(c1.x, c2.x) && wx <= max(c1.x, c2.x)) ||
          (wx == c3.x && wy >= min(c2.y, c3.y) && wy <= max(c2.y, c3.y)) )
        return true;
    }
    return false;
  }

  bool water_in_path_vh(Cell &c1, Cell &c2, Cell &c3) {
    for (auto i = wtrCl.begin(), e = wtrCl.end(); i != e; ++i) {
      int wx = i->x, wy = i->y;
      if ( (wx == c1.x && wy >= min(c1.y, c2.y) && wy <= max(c1.y, c2.y)) ||
          (wy == c3.y && wx >= min(c2.x, c3.x) && wx <= max(c2.x, c3.x)) )
        return true;
    }
    return false;
  }

  bool water_in_path(Cell &c1, Cell &c2, Cell &c3, MOV_SEQ sq) {
    return (sq == HOR_VER) ? water_in_path_hv(c1, c2, c3) : water_in_path_vh(c1, c2, c3);
  }

  void next_mov(Cell &s, Cell &range_end, Cell &d, Cell &out, MOV_SEQ sq)  {
    if (!cell_range_ok(s) || !cell_range_ok(range_end) || !cell_range_ok(d)) {
      SET_CELL_BAD(out);
      return;
    }

    if (water_in_path(s, range_end, d, sq)) {
      SET_CELL_BAD(out);
      return;
    }
    SET_CELL(d, out);
  }

  void countPathToDst(int di) {
    int count = 0;
    for(int i=0; i<(R*C); i++) {
      count += ((dstMap[di])->at(i) > 0) ? 1 : 0;
    }
    if(count > 0) {
      if(count & 1)
        odds += 1;
      else
        evens += 1;
    }
  }

  void getStats() {  for (int d = 0; d<(R*C); d++)  countPathToDst(d);  }
  void setPathMarked(Cell &d, Cell &s) { (dstMap[OFST(d)])->at(OFST(s)) += 1; }
  bool pathFoundBetween(Cell &d, Cell &s) { return ((dstMap[OFST(d)])->at(OFST(s)) > 0); }
  void recordPathBetween(Cell &d, Cell &s) { setPathMarked(d, s); setPathMarked(s, d); }

  void printOddsEvens(int caseId) {
    cout << "Case " << caseId << ":" << " " << evens << " " << odds << "\n";
  }

  #define TRY_MOVE(dx1, dy1, dx2, dy2, dir) \
    do { \
      if (isFoundInSearchPathListAlready(src)) { \
        break; \
      } \
      addToSearchPathList(src); \
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
      next_mov(src, tmp, dst, out, dir); \
      if(!IS_BAD_CELL(out)) { \
        recordPathBetween(dst, src); \
        dfs(dst); \
      } \
      removeFromSearchPathList(src); \
    } while(0)

  void dfs(Cell src) {
    TRY_MOVE( M, 0, 0, -N, HOR_VER); TRY_MOVE(0, -N,  M, 0, VER_HOR);
    TRY_MOVE( M, 0, 0,  N, HOR_VER); TRY_MOVE(0,  N,  M, 0, VER_HOR);
    TRY_MOVE(-M, 0, 0, -N, HOR_VER); TRY_MOVE(0, -N, -M, 0, VER_HOR);
    TRY_MOVE(-M, 0, 0,  N, HOR_VER); TRY_MOVE(0,  N, -M, 0, VER_HOR);

    TRY_MOVE(0,  M,  N, 0, VER_HOR); TRY_MOVE(N,  0,  0, M, HOR_VER);
    TRY_MOVE(0,  M, -N, 0, VER_HOR); TRY_MOVE(-N,  0, 0, M, HOR_VER);
    TRY_MOVE(0, -M,  N, 0, VER_HOR); TRY_MOVE(N, 0,  0, -M, HOR_VER);
    TRY_MOVE(0, -M, -N, 0, VER_HOR); TRY_MOVE(-N, 0, 0, -M, HOR_VER);
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
    kwg.dfs(Cell(0, 0));
    kwg.getStats();
    kwg.printOddsEvens(++caseId);
  }
}
