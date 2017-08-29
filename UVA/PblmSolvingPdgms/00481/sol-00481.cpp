// 481 - What Goes Up
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=422
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <limits>

using namespace std;
typedef vector<int> vi_t;
typedef vector<int> * vi_tp;

struct TMX {
  vi_tp v;
  int tmx; // tail max value at tail at
  TMX(vi_tp _v, int t) : v(_v), tmx(t) { }
  bool operator<(const TMX &rhs) const { return tmx < rhs.tmx; }
  bool operator>(const TMX &rhs) const { return tmx > rhs.tmx; }
  bool operator==(int x) const { return tmx == x; }
  // bool operator=(const TMX &rhs) { v = rhs.v; tmx = rhs.tmx; }
};

struct MXL {
  vi_tp v;
  int ml; // maxlen
};

class WGU {
  public:
  vi_t vi;
  list< vi_tp > lst;
  set<TMX> stmx;
  TMX sm, lg;

  WGU(): sm(0, numeric_limits<int>::max()), lg(0, numeric_limits<int>::min()) { }

  void print() {
    for(auto &t : stmx) {
      //cout << " ti.v " << t.v << " t.ml " << t.tmx << endl;
      auto &v = *t.v;
      //cout << " vi.size () " << v.size() << endl;

      for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
      }
      cout << endl << "--" << endl;
    }
  }

  void checkNsetIfSmallest(TMX &t) {
    if(t<sm)
      sm = t;
  }

  void checkNsetIfLargest(TMX &t) {
    if(t>lg)
      lg = t;
  }

  void add(int x) { vi.push_back(x); }
  bool smallest(int c) { return c < sm.tmx; }
  bool largest(int c) { return c > lg.tmx; }

  void newActiveList(int c) {
    vi_tp vp = new vi_t ();
    vp->push_back(c);
    TMX t(vp, vp->at(0));
    stmx.insert(t);
    checkNsetIfSmallest(t);
    checkNsetIfLargest(t);
  }

  TMX longest() {
    int m = 0; TMX t(0,0);

    for(auto s: stmx) {
      vi_tp v = s.v;
      if(v->size() > m) {
        m = v->size();
        t = s;
      }
    }
    return t;
  }

  void handleLargest(int c) {
    TMX t = longest();
    vi_tp v = t.v;
    vi_tp vp = new vi_t (*t.v);
    vp->push_back(c);
    // cout << " handleLargest vp->size() " << vp->size();
    t = TMX(vp, vp->at(vp->size()-1));
    stmx.insert(t);
    checkNsetIfLargest(t);
  }

  void handleInBetween(int c) {
    // cout << " handleInBetween " << endl;
    int m = numeric_limits<int>::max();
    vi_tp n = 0;

    for(auto s: stmx) {
      vi_tp v = s.v;
      int d = c - (v->at(v->size()-1));
      if(!d)
        return;

      if(d>0 && d<m ) {
        m = d;
        n = v;
      }
    }
    // cout << " handleInBetween 3 n " << n << endl;
    vi_tp vp = new vi_t (*n);
    vp->push_back(c);
    int rsz = vp->size();
    // cout << " handleInBetween 4 " << endl;
    auto it = stmx.begin();
    while(it != stmx.end()) {
      vi_tp v = it->v;
      if(v->size() == rsz) {
        // it->v->clear();
        // delete(it->v);
        it = stmx.erase(it);
      } else {
        it++;
      }
    }
    // cout << " handleInBetween 4 " << endl;
    auto t = TMX(vp, vp->at(vp->size()-1));
    stmx.insert(t);
    checkNsetIfLargest(t);
    checkNsetIfSmallest(t);
  }

  void solve() {
    newActiveList(vi[0]);

    for(int i=1; i< vi.size(); i++) {

      int c = vi[i];
      // cout << "========== " << c << endl;
      if(smallest(c)) {
        // cout << " smallest(c) " << endl;
        newActiveList(c);
      }
      else if(largest(c)) {
        // cout << " largest(c) " << endl;
        handleLargest(c);
      }
      else {
        handleInBetween(c);
      }
      // print();
    }
    // cout << endl;

  } // void solve()

  void printResult() {
    int m = 0;
    vi_tp n = 0;

    for(auto s: stmx) {
      vi_tp v = s.v;
      if(v->size() > m) {
        m = v->size();
        n = v;
      }
    }

    cout << n->size() << endl;
    cout << "-";
    for(int i=0; i<n->size(); i++) {
      cout << endl << n->at(i);
    }
    cout << endl;
  }
};

int main() {
  int x;
  WGU wgu;
  while (cin >> x) { wgu.add(x); }
  wgu.solve();
  wgu.printResult();
}
