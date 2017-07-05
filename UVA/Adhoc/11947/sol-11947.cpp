// 11947 - Cancer or Scorpio
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3098
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef long long lli;
enum {JAN = 0, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
const lli ny[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
lli dayX=-1, monthX=-1;

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
    lli mon = month-1, count = 0, i = JAN;
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
  void addSigns(lli m1, lli d1, lli m2, lli d2, vector<lli> &v, lli year) {
    v.push_back(m1); v.push_back(d1);
    v.push_back(m2), v.push_back(d2);
    v.push_back(getDayOfTheYear(d1,m1,year));
    v.push_back(getDayOfTheYear(d2,m2,year));
  }

  void addSigns(vector<lli> &v, lli year) {
    addSigns(1, 21, 2, 19, v, year); //Aquarius January, 21 February, 19
    addSigns(2, 20 ,3 ,20 , v, year);// Pisces February, 20 March, 20
    addSigns(3, 21 ,4 ,20 , v, year);// Aries March, 21 April, 20
    addSigns(4, 21 ,5 ,21 , v, year);// Taurus April, 21 May, 21
    addSigns(5, 22 ,6 ,21 , v, year);// Gemini May, 22 June, 21
    addSigns(6, 22 ,7 ,22 , v, year);// Cancer June, 22 July, 22
    addSigns(7, 23 ,8 ,21 , v, year);// Leo July, 23 August, 21
    addSigns(8, 22 ,9 ,23 , v, year);// Virgo August, 22 September, 23
    addSigns(9, 24 ,10 ,23 , v, year);// Libra September, 24 October, 23
    addSigns(10, 24 ,11 ,22 , v, year);// Scorpio October, 24 November, 22
    addSigns(11, 23 ,12 ,22 , v, year);// Sagittarius November, 23 December, 22
    addSigns(12, 23 ,1 ,20 , v, year);// Capricorn December, 23 January, 20
  }

  string getStarSign(int i) {
    string s[] = {
      string("aquarius"), string("pisces"), string("aries"), string("taurus"),
      string("gemini"), string("cancer"), string("leo"), string("virgo"),
      string("libra"), string("scorpio"), string("sagittarius"), string("capricorn") };
    return string(s[i]);
  }

  string getStarSign(lli dayOfYear, lli year) {
    vector<lli> v;
    addSigns(v, year);
    int i = 0;
    while(i<v.size()-1) {
      lli start = v[i+4];
      lli end = v[i+5];
      if(dayOfYear >= start && dayOfYear <=end) {
        return getStarSign(i/6);
      }
      i+=6;
    }
    return getStarSign(11);
  }

  void printResult(lli month, lli day, lli year, string sign) {
      static int caseCount = 1;
      printf("%d %.2lld/%.2lld/%.4lld %s\n", caseCount++, month, day, year, sign.c_str());
  }

  void solve() {
    lli curDayOfYear = getDayOfTheYear(d,m,y);
    lli totalDaysForYear = getTotalDays(y);
    lli remainingDaysForYear = totalDaysForYear - curDayOfYear;
    lli year = y;
    lli gt = 7 * 40;// gestation time;
    lli estDay = curDayOfYear + gt;

    if(estDay <= totalDaysForYear) {
    }
    else {
      estDay = gt - remainingDaysForYear;
      year += 1;
    }
    convertOffsetToDay(estDay, year, &dayX, &monthX);
    string sg = getStarSign(estDay, year);
    printResult(monthX+1, dayX, year, sg);
  }

}; // class

vector<lli> getArgs(string s) {
  lli x;  vector<lli> vlli;
  char c[11];
  c[10] = '\0';
  int y = 0, i = 0;

  while(i<8) {
    if(y==2 || y==5){
      c[y++] = ' ';
      continue;
    }
    c[y++] = s[i++];
  }
  string cs(c);
  stringstream ss (cs);
  ss >> x; vlli.push_back(x);
  ss >> x; vlli.push_back(x);
  ss >> x; vlli.push_back(x);
  return vlli;
}

int main() {
  string s;
  int T = 0;
  cin >> T;
  cin.ignore();
  while(T--) {
    while(getline(cin, s)) {
      vector<lli> v = getArgs(s);
      Y3K y(v[1], v[0], v[2], 0);
      y.solve();
    }
  }
}
