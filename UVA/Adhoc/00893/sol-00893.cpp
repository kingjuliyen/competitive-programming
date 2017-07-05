// 893 - Y3K Problem
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=834
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef long long lli;
enum {JAN = 0, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
const lli ny[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Y3K {
public:
  lli d, m, y, ofst; // day month year offset
  Y3K(lli _d, lli _m, lli _y, lli _ofst): d(_d), m(_m), y(_y), ofst(_ofst) {
  }

  bool isLeap(lli y) {
    if(y%400 == 0) {
      return true;
    }
    if(y%100 == 0) {
      return false;
    }
    if(y%4 == 0) {
      return true;
    }
    return false;
  }

  lli getMonthDays(lli month, lli year) {
    lli d = ny[month];
    if(month == FEB) {
      return isLeap(year) ? (d+1): d;
    }
    return d;
  }

  lli getNextMonth(lli month) {
    return month == DEC ? JAN : ++month;
  }

  lli getDayOfTheYear(lli day, const lli month, lli year) {
    lli mon = month-1;
    lli count = 0;
    lli i = JAN;

    while(true) {
      if(i==mon)
        break;
      count += getMonthDays(i, year);
      i = getNextMonth(i);
    }
    count += day;
    return count;
  }

  lli getTotalDays(lli year) {
    return isLeap(year) ? 366 : 365;
  }

  void convertOffsetToDay(lli of, lli year, lli *dayX, lli *monthX) {
    lli counter = 0, days = 0;
    lli month = -1;

    for(lli i = JAN; i<=DEC; i++) {
      days = getMonthDays(i, year);
      if((counter+days) >= of) {
        month = i;
        break;
      }
      counter += days;
    }
    *dayX = of-counter;
    *monthX = month;
  }

  void handleForSingleYear() {
    lli curDayOfYear = getDayOfTheYear(d,m,y);
    lli totalDaysForYear = getTotalDays(y);
    lli remainingDaysForYear = totalDaysForYear - curDayOfYear;
    lli of = ofst;
    lli year = y;

    if((of-remainingDaysForYear) >0) {
      curDayOfYear = of - remainingDaysForYear;
      of = 0;
      year++;
    }

    lli dayX=-1, monthX=-1;
    convertOffsetToDay(curDayOfYear+of, year, &dayX, &monthX);
    printf("%lld %lld %lld\n", dayX, monthX+1, year);
  }

  void handleForYear(lli day, lli month, lli year, lli of, lli counter) {
    lli curDayOfYear = getDayOfTheYear(day,month,year);
    lli totalDaysForYear = getTotalDays(year);
    lli remainingDaysForYear = totalDaysForYear - curDayOfYear;

    while(true) {
      if((of-counter) > remainingDaysForYear) {
        counter += remainingDaysForYear;
        year++;
        curDayOfYear = getDayOfTheYear(0,1,year);
        totalDaysForYear = getTotalDays(year);
        remainingDaysForYear = totalDaysForYear - curDayOfYear;
        continue;
      } else {
        if(counter == 0) {
          handleForSingleYear();
          return;
        }
        lli dayX=-1, monthX=-1;
        convertOffsetToDay(of-counter, year, &dayX, &monthX);
        printf("%lld %lld %lld\n", dayX, monthX+1, year);
        break;
      }
    }
  }

  void solve() {
    handleForYear(d, m, y, ofst, 0);
  }
}; // class

vector<lli> getArgs(string s) {
  lli x;  vector<lli> vlli; stringstream ss(s);
  for(lli i=0; i<4;i++) { ss >> x; vlli.push_back(x); }
  return vlli;
}

int main() {
  string s;
  while(getline(cin, s)) {
    vector<lli> v = getArgs(s);
    if(!v[1] && !v[2] && !v[3] && !v[0])
      break;
    Y3K y(v[1], v[2], v[3], v[0]);
    y.solve();
  }
}
