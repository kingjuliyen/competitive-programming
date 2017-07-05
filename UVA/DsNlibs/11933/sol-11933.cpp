// 11933 - Splitting Numbers
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3084
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int uint_t;

void handle(uint_t x) {
  uint_t an = 0;
  uint_t bn = 0;
  vector<int> vi;
  for(int i=0; i<31; i++){
    uint_t mask = 1 << i;
    if(mask & x)
      vi.push_back(i);
  }
  for(int i=0; i<vi.size();i++){
    uint_t index = vi[i];
    uint_t mask = 1 << index;
    if((i+1) & 1) { // odd
      an |= mask;
    } else {
      bn |= mask;
    }
  }
  cout << an << " " << bn << "\n";
}

int main() {
  while(true) {
    uint_t x;
    cin >> x;
    if(!x)
      break;
    handle(x);
  }
}
