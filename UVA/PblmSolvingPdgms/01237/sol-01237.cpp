// 1237 - Expert Enough?
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3678
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

// to compile : c++ sol-01237.cpp -std=c++11
// delete not done so some memleak is there

#include <iostream>
#include <map>

using namespace std;

struct LnH {
  int L, H;
  LnH(int _L, int _H) : L(_L), H(_H) { }
  bool inrange(int p) { return (p >= L && p <= H ); }
};

class ExEn { // ExpertEnough
  map <string, LnH *> lnhMap;
  public:
  void addToDB(string mdl, int L, int H) {
    lnhMap[mdl] = new LnH(L,H);
  }

  string getModel(int q) {
    string mdl;
    int count = 0;
    for(auto i :lnhMap) {
      LnH *lnh = i.second;
      if(lnh->inrange(q)) {
        count++;
        if(count > 1) {
          break;
        }
        mdl = i.first;
      }
    }
    return(count == 1) ? mdl : "UNDETERMINED";
  }
};

int main() {
  int T, D, Q, P, L, H;
  
  cin >> T;
  while(T--) {
    cin >> D;
    ExEn exen;

    while(D--) {
      string model;
      cin >> model >> L >> H;
      exen.addToDB(model, L, H);
    }

    cin >> Q;
    while(Q--) {
      cin >> P;
      cout << exen.getModel(P) << "\n";
    }
    if(T)
      cout << "\n";
  }
}
