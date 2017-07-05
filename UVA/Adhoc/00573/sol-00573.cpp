// 00573 The Snail
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=514
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>

void simulate(int well_height, float day_climb, int night_slide, int fatigue_percent) {

	int day = 1;
	float position = 0, ftg = (day_climb * fatigue_percent/100);

	while(true) {
		if(day_climb > 0) { // snail doesn't climb -ve distance
			position += day_climb;
			day_climb = day_climb - ftg;
		}
		if(position > (float) well_height) {
			printf("success on day %d\n", day);
			break;
		}

		position -= night_slide;

		if(position < 0) {
			printf("failure on day %d\n", day);
			break;
		}
		day++;
	}
}

int main() {
	int H = -1, U = -1, D = -1, F = -1;

	while(true) {
		scanf("%d %d %d %d", &H, &U, &D, &F);
		if(!H)
			break;
		simulate(H, U, D, F);
	}
	return 0;
}
