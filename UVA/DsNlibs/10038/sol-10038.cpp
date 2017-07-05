// 10038 - Jolly Jumpers
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class JJ { // jolly jumper
public:
  vector<int> vi;
  int N;
  JJ(string s) {
    stringstream ss(s);
    int x;
    ss >> x;
    N = x;
    for (int i=0; i<N;i++) {
      ss >> x;
      vi.push_back(x);
    }
  }

  void printResult(bool b) {
    if(b)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }

  void solve() {
    vector<bool> vb(vi.size(), false);
    vb[0] = true;

    if(vi.size() == 1) {
      printResult(true);
      return;
    }

    for(int i=1; i<vi.size(); i++) {
      int cur = vi[i];
      int prev = vi[i-1];
      int d = abs(prev - cur);
      if(d < vb.size()) {
        vb[d] = true;
      }
    }
    vector<bool>::iterator it = find(vb.begin(), vb.end(), false);
    printResult(it == vb.end());
  }
};

int main() {
  string s;
  while(getline(cin, s)) {
    JJ jj(s);
    jj.solve();
  }
}
