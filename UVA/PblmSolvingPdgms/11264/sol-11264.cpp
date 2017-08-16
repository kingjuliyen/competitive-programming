// 11264 - Coin Collector
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2231
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com
#include <iostream>
#include <vector>
using namespace std;

class CC { public: // Coin Collector
  int n; vector<int> ct; // coin types
  CC(int _n) :n(_n) { }
  void addCoin(int c) { ct.push_back(c); }
  void solve() { }
};

int main() {
  int T, n, c;
  cin >> T;
  while(T--) {
    cin >> n;
    CC cc(n);
    while(n--) {
      cin >> c;
      cc.addCoin(c);
    }
    cc.solve();
  }
}
