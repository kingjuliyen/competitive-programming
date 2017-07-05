// problem: 10189 - Minesweeper
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1130
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

#include <iostream>

using namespace std;

class MS { // MS - mine sweeper
public:
	int R, C;
	char * msp; // mine sweeper pointer

	MS(int _R, int _C);
	~MS();
	char getVal(int r, int c);
	void setVal(int index, char val);
	void setVal(int r, int c, char v);
	void reset();
	void print();
	void solve();

	char checkMine(int r, int c);
	char checkNorth(int r, int c);
	char checkNorthEast(int r, int c);
	char checkEast(int r, int c);
	char checkSouthEast(int r, int c);
	char checkSouth(int r, int c);
	char checkSouthWest(int r, int c);
	char checkWest(int r, int c);
	char checkNorthWest(int r, int c);
};

MS::~MS(){
	delete[] msp;
	msp = 0;
}

MS::MS(int _R, int _C): R(_R), C(_C), msp(0) {
	msp = new char[R*C];
}

char MS::getVal(int r, int c) {
	if(r >= R || c >= C || r < 0 || c < 0)
		return 0;
	return msp[(r*C) + c];
}

void MS::setVal(int r, int c, char v) {
	if(r >= R || c >= C || r < 0 || c < 0)
		return;
	msp[(r*C) + c] = v;
}

void MS::print() {
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			cout << getVal(i,j);
		}
		cout << "\n";
	}
}

char MS::checkMine(int r, int c) {
	if(getVal(r,c) == '*')
		return 1;
	else
		return 0;
}

char MS::checkNorth(int r, int c) { return checkMine(r-1,c); }

char MS::checkNorthEast(int r, int c) {	return checkMine(r-1,c+1); }

char MS::checkEast(int r, int c) {	return checkMine(r,c+1); }

char MS::checkSouthEast(int r, int c) {	return checkMine(r+1,c+1); }

char MS::checkSouth(int r, int c) {	return checkMine(r+1,c); }

char MS::checkSouthWest(int r, int c) {	return checkMine(r+1,c-1); }

char MS::checkWest(int r, int c) {	return checkMine(r,c-1); }

char MS::checkNorthWest(int r, int c) { return checkMine(r-1,c-1); }

void MS::solve() {
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if(getVal(i,j) == '*')
				continue;
			char v = 0;
			v += checkNorth(i, j);
			v += checkNorthEast(i, j);
			v += checkEast(i, j);
			v += checkSouthEast(i, j);
			v += checkSouth(i, j);
			v += checkSouthWest(i, j);
			v += checkWest(i, j);
			v += checkNorthWest(i, j);
			v += '0';
			setVal(i, j, v);
		}
	}
}

int main() {
	int count = 1;
	while(true) {
		int N = 0, M = 0;
		cin >> N >> M;

		if(N==0 || M == 0)
			break;

		MS m(N, M);

		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				char v = -1;
				cin >> v;
				m.setVal(i, j, v);
			}
		}

		m.solve();
		if(count >1)
			cout << "\n";
		cout << "Field #" << count << ":\n"; count++;
		m.print();
	}
}
