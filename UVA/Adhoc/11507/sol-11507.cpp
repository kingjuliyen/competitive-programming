// 11507 - Bender B. Rodríguez Problem
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2502
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string xp = "+x";
string xn = "-x";
string yp = "+y";
string yn = "-y";
string zp = "+z";
string zn = "-z";

enum state {XP, XN, YP, YN, ZP, ZN, UNK};

#if 0
	 y-	y+	z-	z+
	 --------------
x- | y+	y-	z+	z-
x+ | y-	y+	z-	z+
y- | x-	x+	y-	y-
y+ | x+	x-	y+	y+
z- | z-	z-	x-	x+
z+ | z+	z+	x+	x-
#endif

state cur = XP;

state do_yn(state _cur) {
	state s = UNK;
	switch(_cur) {
		case XN:
			s = YP;
			break;
		case XP:
			s = YN;
			break;
		case YN:
			s = XN;
			break;
		case YP:
			s = XP;
			break;
		case ZN:
			s = ZN;
			break;
		case ZP:
			s = ZP;
			break;
		case UNK:
			break;
	}
	return s;
}

state do_yp(state _cur) {
	state s = UNK;
	switch(_cur) {
		case XN:
			s = YN;
			break;
		case XP:
			s = YP;
			break;
		case YN:
			s = XP;
			break;
		case YP:
			s = XN;
			break;
		case ZN:
			s = ZN;
			break;
		case ZP:
			s = ZP;
			break;
		case UNK:
			break;
	}
	return s;
}

state do_zn(state _cur) {
	state s = UNK;
	switch(_cur) {
		case XN:
			s = ZP;
			break;
		case XP:
			s = ZN;
			break;
		case YN:
			s = YN;
			break;
		case YP:
			s = YP;
			break;
		case ZN:
			s = XN;
			break;
		case ZP:
			s = XP;
			break;
		case UNK:
			break;
	}
	return s;
}

state do_zp(state _cur) {
	state s = UNK;
	switch(_cur) {
		case XN:
			s = ZN;
			break;
		case XP:
			s = ZP;
			break;
		case YN:
			s = YN;
			break;
		case YP:
			s = YP;
			break;
		case ZN:
			s = XP;
			break;
		case ZP:
			s = XN;
			break;
		case UNK:
			break;
	}

	return s;
}

void printResult(state _c) {
	switch(_c) {
		case XN:
			cout << "-x\n";
			break;
		case XP:
			cout << "+x\n";
			break;
		case YN:
			cout << "-y\n";
			break;
		case YP:
			cout << "+y\n";
			break;
		case ZN:
			cout << "-z\n";
			break;
		case ZP:
			cout << "+z\n";
			break;
		case UNK:
			break;
	}
}

void nextMove(string m) {
	if(m == yn) { cur = do_yn(cur); }
	else if(m == yp) { cur = do_yp(cur); }
	else if(m == zn) { cur = do_zn(cur); }
	else if(m == zp) { cur = do_zp(cur); }
	// string "No" ignored automatically
}

int main() {
	int T = 0;
	string mv;

	while(true) {
		cin >> T;
		if(!T)
			break;
		cur = XP;

		for(int i=0; i<T-1; i++) {
			cin >> mv;
			nextMove(mv);
		}
		printResult(cur);
	}
	return 0;
}
