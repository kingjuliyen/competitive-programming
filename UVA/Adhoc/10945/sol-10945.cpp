// 10945 - Mother bear
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1886
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class MB { // MOTHER BEAR
public:
  MB(string s);
};

void print(vector<char> &vc) {
  for(int i=0; i<vc.size(); i++) {
    cout << vc[i];
  }
  cout << "\n";
}

void checkPalindrome(vector<char> &vc) {
  int half_limit = vc.size()/2;
  int len = vc.size();
  for(int i=0; i<half_limit; i++) {
    char start = vc[i];
    char end = vc[len-i-1];
    if(start != end) {
      cout << "Uh oh.." << "\n";
      return;
    }
  }
  cout << "You won't be eaten!" << "\n";
}

MB::MB(string s) {
  const char * cp = s.c_str();
  vector<char> vc;
  int d = 'a' - 'A';

  for(int i=0; i<s.length(); i++) {
    char c = cp[i];
    if(c >= 'A' && c <= 'Z') {
      vc.push_back(c);
    }
    if(c >= 'a' && c <= 'z') {
      vc.push_back(c-d);
    }
  }
  checkPalindrome(vc);
}

int main() {
  string s;
  while(getline(cin,s)) {
    if(s == "DONE")
      break;
    MB mb(s);
  }
}
