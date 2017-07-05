// Nlogonia
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2493
// author: Senthil Kumar Thangavelu

#include <cstdio>

const char * DIV = "divisa";
const char * NO = "NO"; // NW
const char * NE = "NE"; // NE
const char * SE = "SE"; // SE
const char * SO = "SO"; // SW

void print_division(int mx, int my, int cx, int cy) {
	const char * c = 0;

	do {
		if(cx == mx || cy == my) {
			c = DIV;
			break;
		}

		if(cx > mx && cy > my) {
			c = NE;
			break;
		}

		if(cx > mx && cy < my) {
			c = SE;
			break;
		}

		if(cx < mx && cy < my) {
			c = SO;
			break;
		}

		if(cx < mx && cy > my) {
			c = NO;
			break;
		}

	} while(0);


	printf("%s\n",c);
}

int main() {
	int TC = 0, mx = 0, my = 0, cx = 0, cy = 0;

	while(1) {
		scanf("%d", &TC);
		if(!TC)
			break;
		scanf("%d %d", &mx, &my);
		while(TC--) {
			scanf("%d %d", &cx, &cy);
			print_division(mx, my, cx, cy);
		}
	}
}
