// 10107 - What is the Median?
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1048
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline bool isOdd(){
  static bool b = true;
  return b ? !(b = false) : !(b = true);
}

typedef unsigned int int_type;
int main() {
  int_type x;
  int_type count = 0;
  vector<int_type> * ar = new vector<int_type>(10000+1);
  int_type m1 =-1;

  while(cin >> x) {
    ar->at(count) = x;
    count++;
    sort(ar->begin(), ar->begin()+count);

    int mid = count/2;
    if(isOdd()) {
      m1 = ar->at(mid);
    } else {
      m1 = (ar->at(mid) + ar->at(mid-1)) / 2;
    }
    cout << m1 << "\n";
  }
}
