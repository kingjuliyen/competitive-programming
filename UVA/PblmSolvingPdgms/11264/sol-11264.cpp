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
          
  // Refer to  howto-solve-11264.pdf in the current folder, to understand how this problem is solved
  // Greedy approach used
  void solve() { 
    int sum = ct[0],  nc = 0 /* nc == number of coin */;
    for(int cci=1; cci<ct.size()-1; cci++) { // cci -> current coin index
      if(sum+ct[cci] < ct[cci+1]) {
        sum += ct[cci];
        nc++;
      }
    }
    // why +2 is added -> first coin "ct[0]" and last coin "ct[ct.size()-1]" are always chosen
    // if first coin is not a '1' more likely to get into infinte loop and bank's algo won't converge, so 1 is always chosen
    // any value higher than last element(highest index) will definitely use last element(highest index) coin
    cout << nc + 2  << endl; 
  }
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


#if 0
/////////////////////////////////////////////////////////////////////////////
// CODE BELOW IS NOT REQUIRED TO SOLVE THE PROBLEM, IT JUST HELPS UNDERSTAND 
// HOW THE BANKER'S ALGORITHM WORKS FOR ANY GIVEN AMOUNT x
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> v = {1, 2, 4, 8, 16, 32};
// vector<int> v = {1, 3, 6, 8, 15, 20};

map<int, bool> m;

void w(int x) {
  if(x==0)
    return;
  cout << "\t\t\t amount " << x;
  int c = -1;
  for(int i=v.size()-1; i>=0; i--) {
    // cout << "\t\t\t" << v[i] << endl;
    if(v[i] <= x) {
      c = v[i];
      break;
    }
  }
  m[c] = true;
  cout << " coin " << c << endl;
  w(x-c);
}

int main() {
  int mx = -1;
  for(int i=7; i<=7; i++) {
    m.clear();
    cout << " \n\n########## " << i <<"  ########### " << endl;
    w(i);
    cout << "m.size() " << m.size() << endl;
    mx = max<int>(mx,m.size());
  }
  cout << "max " << mx << endl;
}
#endif