// 481 - What Goes Up
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=422
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>

using namespace std;

class WGU {
  public:
  vector<int> vi;
  WGU() { }
  void add(int x) { vi.push_back(x); }
  void solve() { }
};

int main() {
  int x;
  WGU wgu;
  while (cin >> x) { wgu.add(x); }
  wgu.solve();
}