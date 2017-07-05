// 732 - Anagrams by Stack
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=673
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define PUSH 'i'
#define POP 'o'

string src, tgt;
int pushCount = 0, popCount = 0, maxTgtLen = 0, tgtLen;
char seqAr[300], stack_[300];

inline void printSequence(int seqIdx) {
  int Ntimes = tgtLen-1;
  int x = 0;
  for(int i=0; i<Ntimes; i++) {
    printf("%c %c ",seqAr[x], seqAr[x+1]);
    x+=2;
  }
  printf("%c %c\n", seqAr[x], seqAr[x+1]);
}

inline bool simulateStackInstructions(int seqIdx) {
  int si = 0, ti = 0, stp = 0; // source index, target index, stack pointer
  const char *src_cc = src.c_str(), *tgt_cc = tgt.c_str();

  for(int i=0; i<seqIdx; i++) {
    if(seqAr[i]== PUSH ) {
      stack_[stp++] = src_cc[si++];
    }
    else { // seqAr[i]== POP
      if(stack_[--stp] != tgt_cc[ti++])
        return false;
    }
  }
  return true;
}

bool invalidSequence() {
  return ((popCount > pushCount) || (pushCount > tgtLen));
}

bool maxSearchDepth(int seqIdx) {
  return (seqIdx > (maxTgtLen));
}

void solve(int seqIdx, char type) {
  if(invalidSequence() || maxSearchDepth(seqIdx))
    return;

  if(!simulateStackInstructions(seqIdx))
    return;
  else {
    if(seqIdx == maxTgtLen) {
      printSequence(seqIdx);
      return;
    }
  }

  int nextSeq = seqIdx +1;
  /* SIMULATE A PUSH STATE */
  seqAr[seqIdx] = PUSH;
  pushCount++;
  solve(nextSeq, PUSH);
  pushCount--;

  /* SIMULATE A POP STATE */
  seqAr[seqIdx] = POP;
  popCount++;
  solve(nextSeq, POP);
  popCount--;
}

void init(string s, string t){
  pushCount = 1;  popCount = 0;
  src = s;  tgt = t;
  tgtLen = s.length();
  maxTgtLen = tgtLen * 2;
  seqAr[0] = PUSH;
}

inline void solve(string s, string t) {
  cout << "[\n";

  if(s.size() != t.size()) {
    cout << "]\n";
    return;
  }

  init(s, t);
  solve(1, PUSH);

  cout << "]\n";
}

int main() {
  while(true) {
    string s;
    string t;
    if(!(cin >> s))
      break;
    cin >> t;
    solve(s, t);
  }
}
