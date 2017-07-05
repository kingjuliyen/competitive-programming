// 403 - Postscript
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=344
// udebug has got good test cases
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int caseCount;
//A B C D E F G H I
char c51[]=
".***..****...****.****..*****.*****..****.*...*.*****."
"*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*..."
"*****.****..*.....*...*.***...***...*..**.*****...*..."
"*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*..."
"*...*.****...****.****..*****.*......***..*...*.*****.";
// J K L M N O P Q R
char c52[] =
"..***.*...*.*.....*...*.*...*..***..****...***..****.."
"...*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*."
"...*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****.."
"*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*.."
".**...*...*.*****.*...*.*...*..***..*......****.*...*.";
// S T U V W X Y Z blank
char c53[] =
".****.*****.*...*.*...*.*...*.*...*.*...*.*****......."
"*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*........"
".***....*...*...*..*.*..*.*.*...*.....*.....*........."
"....*...*...*...*..*.*..**.**..*.*....*....*.........."
"****...***...***....*...*...*.*...*...*...*****.......";

class Font {
public:
  char c;
  char * bitmap;
  Font(char _c): c(_c) { bitmap = new char[5*6]; }
  void print() {
    int i = 0;
    for(int row = 0; row<5; row++){
      for(int col = 0; col<6; col++) {
        printf("%c",bitmap[i++]);
      }
      printf("\n");
    }
  }
}; // class Font

map <char, Font * > fm; // font map
void extractFont(char c, int charOffset, char p[]) {
  Font * f = new Font(c);
  int xOffset = charOffset * 6;
  int d = 0;
  for(int row =0; row<5; row++) {
    int rowOffset = row * 9 * 6;
    int s = xOffset + rowOffset;
    f->bitmap[d++] = p[s++];
    f->bitmap[d++] = p[s++];
    f->bitmap[d++] = p[s++];
    f->bitmap[d++] = p[s++];
    f->bitmap[d++] = p[s++];
    f->bitmap[d++] = p[s++];
  }
  fm[c] = f;
}

void initC5Fonts() {
  int charOffset = 0;
  for(char c = 'A', charOffset = 0; c<='I'; c++) {
    extractFont(c, charOffset++, c51);
  }
  for(char c = 'J', charOffset = 0; c<='R'; c++) {
    extractFont(c, charOffset++, c52);
  }
  for(char c = 'S', charOffset = 0; c<='Z'; c++) {
    extractFont(c, charOffset++, c53);
  }
  extractFont(' ', 8, c53);
}

class PSP {
public:
  vector <string> cmds;
  char *bmp;
  char *writeTracker;

  PSP() {
    int sz = 60*60;
    bmp = new char[sz];
    writeTracker = new char[sz];
    for(int i=0; i<sz; i++) {
      writeTracker[i] = 0;
      bmp[i] = '.';
    }
  }

  void addCommands(string s) {
    cmds.push_back(s);
  }

  string getMsgString(stringstream &ss, string &cmd) {
    size_t start = ss.tellg()+2LL;
    string str(cmd, start, (cmd.length() - ss.tellg() -3));
    return str;
  }

  void write(int offset, char v) {
    if(v == '.')
      return;
    char c = bmp[offset];
    bmp[offset] = v;
  }

  void writeC1(int offset, char v) {
      bmp[offset] = v;
  }

  void paintC1(int r, int c, char v) {
    if(v == ' ')
      return;
    if(r < 0 || r >= 60)
      return;
    if(c < 0 || c >= 60)
      return;
    int ofst = (r*60) + c;
    writeC1(ofst, v);
  }

  void paintC1(int r, int c, string msg){
    for(int i=0; i<msg.length(); i++) {
      paintC1(r, c, msg[i]);
      c+=1;
    }
  }

  void paintC5(int r, int c, char v){
    Font *f = fm[v];
    int d = 0;

    for(int row = r; row < (r+5); row++) {
      for(int col = c; col < (c+6); col++) {
        if(row <0||row >= 60) {
          d++;
          continue;
        }
        if(col <0 || col >= 60) {
          d++;
          continue;
        }
        int ofst = (row*60)+col;
        write(ofst, f->bitmap[d]);
        d++;
      }
    }
  }

  void paintC5(int r, int c, string msg){
    for(int i=0; i<msg.length(); i++) {
      if( msg[i] != ' ') {
        paintC5(r, c, msg[i]);
      }
      c+=6;
    }
  }

  void paintString(int r, int c, string msg, string fontType) {
    if(fontType=="C1") {
      paintC1(r,c,msg);
    }
    if(fontType == "C5") {
      paintC5(r,c,msg);
    }
  }

  void handlePlaceString (string cmd) {
    stringstream ss(cmd);
    string s, fonttype;
    int r = -1, c = -1;
    ss >> s;
    ss >> fonttype;
    ss >> r;
    ss >> c;
    string msg = getMsgString(ss, cmd);
    paintString(r-1, c-1, msg, fonttype);
  }

  void handleLeftJustify (string cmd) {
    stringstream ss(cmd);
    string s, fonttype;
    int r = -1;

    ss >> s;
    ss >> fonttype;
    ss >> r;
    string msg = getMsgString(ss, cmd);
    paintString(r-1, 0, msg, fonttype);
  }

  void handleRightJustify (string cmd) {
    stringstream ss(cmd);
    string s, fonttype;
    int r = -1;

    ss >> s;
    ss >> fonttype;
    ss >> r;
    string msg = getMsgString(ss, cmd);

    int c = -1;
    if(fonttype == "C1") {
      c = 60 - msg.length();
    }
    else {
      c = 60 - (msg.length()*6);
    }
    paintString(r-1, c, msg, fonttype);
  }

  void handleCenterString (string cmd) {
    stringstream ss(cmd);
    string s, fonttype;
    int r = -1;
    ss >> s;
    ss >> fonttype;
    ss >> r;
    string msg = getMsgString(ss, cmd);

    unsigned int odd = msg.length() & 1;
    int c = -1;

    if(odd) {
      if(fonttype == "C1") {
        int mid = 30;
        c = mid - (msg.length()/2);
      } else {
        int mid = 30;
        c = mid - ((msg.length()/2)*6) - 3;
      }
    }
    else {
      int mid = 30;
      if(fonttype == "C1") {
        c = mid - (msg.length()/2);
      } else {
        c = mid - ((msg.length()/2)*6);
      }
    }
    paintString(r-1,c,msg, fonttype);
  }

  void handleCmd(string cmd) {
    if(!(cmd[0]=='.'))
      return;

    switch (cmd[1]) {
      case 'P':
        handlePlaceString(cmd);
        break;
      case 'L':
        handleLeftJustify(cmd);
        break;
      case 'R':
        handleRightJustify(cmd);
        break;
      case 'C':
        handleCenterString(cmd);
        break;
    }
  }

  void print() {
    int x = 0;
    if(caseCount>0)
      cout << "\n";
    for(int i=0; i<60; i++) {
      for(int j=0; j<60; j++) {
        cout << bmp[x++];
      }
      cout << "\n";
    }
    cout << "\n";
    for(int i=0; i<60; i++) {
      cout << "-";
    }
    cout << "\n";
  }

  void solve() {
    for(int i=0; i<cmds.size(); i++) {
      handleCmd(cmds[i]);
    }
    print();
  }

}; // class PSP

int main() {
  caseCount = 0;
  initC5Fonts();
  string s;
  PSP * psp = new PSP();
  while(getline(cin, s)) {
    if(s == ".EOP") {
      psp->solve();
      caseCount++;
      psp = new PSP();
      continue;
    }
    psp->addCommands(s);
  }
  cout << "\n";
}
