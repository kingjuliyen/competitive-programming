// 146 - ID Codes
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=82
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  while (true) {
    string s;
    cin >> s;
    if(s=="#")
      break;
    if(next_permutation(s.begin(), s.end())) {
      cout << s << "\n";
    }
    else
      cout << "No Successor\n";
  }
}
