// 11988 - Broken Keyboard
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3139
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAX = 100000+100;

class record {
public:
  record * next;
  int start;
  int end;
  int count;

  record() : start(-1), count(0) {
  }
  void reset() {
    start = -1;
    count = 0;
    next = 0;
  }
}; // class

record *rcs;

class BK {
public:
  record * cr; // current record
  int nxtRecord;
  record head;
  record tail;

  record * getNextRecord() {
    record * r = &rcs[nxtRecord];
    r->reset();
    nxtRecord++;

    if(tail.next == 0)
      tail.next = r;
    return r;
  }

  record * getCurRecord() {
    int idx = nxtRecord - 1;
    if(idx<0)
      return 0;
    record * r = &rcs[idx];
    return r;
  }

  inline void onHome() {
    cr = getNextRecord();
    record *prevR = head.next;
    cr->next = prevR;
    head.next = cr;
  }

  inline void onEnd() {
    record *prev = tail.next;
    cr = getNextRecord();
    if(prev)
      prev->next = cr;
    tail.next = cr;
  }

  void printOutput(const char s[]) {
    record * r = head.next;
    while(true) {
      if(r) {
        if(r->start != -1) {
          printf("%.*s",r->count, s+r->start);
        }
        r = r->next;
      }else {
        break;
      }
      if(r == tail.next) {
        printf("%.*s",r->count, s+r->start);
        break;
      }
    }
    printf("\n");
  }

  void cleanup() {
    nxtRecord = 0;
    head.reset();
    tail.reset();
  }

  void init() {
    nxtRecord = 0;
    head.reset();
    tail.reset();
    onHome();
  }

  void solve(const char s[], int ml) {
    init();

    for(int i=0; i<ml; i++) {
      if(s[i]=='[') {
        onHome();
        continue;
      }
      if(s[i]==']') {
        onEnd();
        continue;
      }
      if(cr->start == -1) {
        cr->start = i;
      }
      cr->count++;
    }
    printOutput(s);
    cleanup();
  }

}; // class BK

int main() {
  string s;
  BK bk;
  int r = 0;
  char * word = new char[MAX];
  rcs = new record[MAX*4];
  int count = 0;
  while(true) {
    r = scanf("%s", word);
    if(r==EOF)
      break;
    int len = strlen(word);
    bk.solve(word, len);
  }
}
