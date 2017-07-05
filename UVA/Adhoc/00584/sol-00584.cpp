// 584 - Bowling
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=525
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int char_to_int (char c) {
  if(c == 'X')
    return 10;
  int x = c - '0';
  return x;
}

int handleStrike(vector<char> & cp, int i) {
  int incr = 0;

  if(cp[i+2] == '/') {
    incr = 10;
  } else {
    incr = char_to_int(cp[i+1]) + char_to_int(cp[i+2]);
  }

  return (10 + incr);
}

int handleSpare(vector<char> & cp, int i) {
  int incr = 0;
  return (10 + char_to_int(cp[i+2]));
}

void Bowling(string s) {
  const char * cp = s.c_str();
  int j = 0, v = 0, x = 0;
  vector<char> vc;
  for(int i = 0; i < s.length(); i++){
    if(cp[i] ==  ' ')
      continue;
    vc.push_back(cp[i]);
  }

  for(int frame =1; frame <= 10; frame++) {
    char c1 = vc[j];
    if(c1 == 'X') {
        v += handleStrike(vc, j);
        j++;
        continue;
    }
    char c2 = vc[j+1];
    if(c2 == '/') {
      v += handleSpare(vc, j);
      j += 2;
      continue;
    } else {
      v += char_to_int(c1) + char_to_int(c2);
      j += 2;
      continue;
    }
  }
  cout << v << "\n";
}

int main() {
  while(true) {
    string s;
    if(!getline(cin, s))
      break;
    if(s == "Game Over"||s == "Game  Over") // satisfy udebug and UVA as well
      break;
    Bowling(s);
  }
}
