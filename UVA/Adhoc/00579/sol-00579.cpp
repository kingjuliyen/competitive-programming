// 579 - Clock Hands
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=520
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <vector>
#include <cmath>

int main() {
  float hour, minute;
  while(scanf("%f:%f",&hour, &minute) == 2) {
    if(!hour && !minute)
      break;
    float d = fabs((minute * 6) - (((minute/12) + (hour*5)) * 6));
    printf("%.3f\n", std::min(d, 360-d));
  }
}
