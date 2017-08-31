// 10616 - Divisible Group Sums
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=18&page=show_problem&problem=1557
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi_t;

struct DGS { // Divisible Group Sums
  vi_t v; int D, M;
  void add(int x) { v.push_back(x); }
  void setDM(int _D, int _M) { D = _D; M = _M; }
  void solve() {
    
  }
};

int main() {
  int N, Q, D, M, x;
  while(true) {
    cin >> N >> Q;
    if(!N && !Q)
      break;
    DGS dgs;
    while(N--) {
      cin >> x;
      dgs.add(x);
    }
    while(Q--) {
      cin >> D >> M;
      dgs.setDM(D, M);
      dgs.solve();
    }

  }
}
