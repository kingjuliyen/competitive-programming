// 10920 - Spiral Tap
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1861
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>
#include <cmath>

typedef long long int64_type;
using namespace std;

bool checkBounds(int64_type offset, int64_type start, int64_type end) {
  if(offset >= start && offset <=end)
    return true;
  return false;
}

void printGlobalCartesian(int64_type row, int64_type col, int64_type SZ, int64_type smallDim, int64_type P) {
  int64_type d = 0;

  if(smallDim < SZ) {
    d = (SZ - smallDim) /2;
    row += d;
    col += d;
  }

  row = SZ - row;
  col += 1;
  cout << "Line = "<< row << ", column = "<< col << ".\n";
}

void printCartesianCoords(int64_type bigDim, int64_type offset, int64_type smallDim, int64_type P, int64_type SZ ) {
  int64_type upStart = 0;
  int64_type upEnd = smallDim - 2;

  int64_type leftStart = upEnd + 1;
  int64_type leftEnd = leftStart + smallDim - 2;

  int64_type bottomStart = leftEnd + 1;
  int64_type bottomEnd = bottomStart + smallDim -2;

  int64_type rightStart = bottomEnd + 1;
  int64_type rightEnd = rightStart + smallDim - 2;

  int64_type row = -1, col = -1;

  if(checkBounds(offset, upStart, upEnd)) {
    row = 0;
    col = upEnd - offset;
  }
  else if (checkBounds(offset, leftStart, leftEnd)) {
    col = 0;
    row = (smallDim -1) - (leftEnd - offset);
  }
  else if (checkBounds(offset, bottomStart, bottomEnd)) {
    row = (smallDim - 1);
    col = (smallDim - 1) - (bottomEnd - offset);
  }
  else if (checkBounds(offset, rightStart, rightEnd)) {
    col = (smallDim - 1);
    row = rightEnd - offset;
  }
  printGlobalCartesian(row, col, SZ, smallDim, P);
}

void solve(int64_type SZ, int64_type P) {
  if(P==1) {
    printGlobalCartesian(0,0,SZ,1,1);
    return;
  }

  if( P== (SZ*SZ)) {
    printGlobalCartesian(0,SZ-1,SZ,SZ,P);
    return;
  }

  int64_type ssq = -1, ssqdim = -1;

  int64_type pd = sqrt(P); // possible dimension
  if(P == pd*pd) {
    if(pd%2==0)
      pd++;
      ssq = pd*pd;
  } else {
    pd++;
    if(pd%2==0)
      pd++;
    ssq = pd*pd;
  }
  ssqdim = pd;

  int64_type sn = sqrt(ssq) - 2; // start number
  sn *= sn;
  sn += 1;

  int64_type offset = -1;
   if(P == ssq) {
     int64_type innerSquares = sqrt(ssq-2);
     offset = ssq - innerSquares;
   }
   else {
     offset = P - sn;
   }
  printCartesianCoords(SZ, offset, ssqdim, P, SZ);
}

int main() {
  while(true) {
    int64_type SZ = -1, P = -1;
    cin >> SZ;
    cin >> P;
    if(SZ==0 && P==0)
      break;
    solve(SZ, P);
  }
}
