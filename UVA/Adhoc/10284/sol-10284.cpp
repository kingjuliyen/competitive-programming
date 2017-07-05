// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com
// 10284 - Chessboard in FEN
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1225

#include <iostream>
#include <cstdio>

using namespace std;
class board {
public:
	board(string s);
	char * bp;
	char get_val(int r, int c);
	void set_val(int r, int c, char v);
	void print();

	void mark_black_pawn_damage(int r, int c);
	void mark_white_pawn_damage(int r, int c);

	void mark_knight_damage(int r, int c);
	void mark_bishop_damage(int r, int c);
	void mark_rook_damage(int r, int c);
	void mark_queen_damage(int r, int c);
	void mark_king_damage(int r, int c);

	void mark_up_right_diagonal(int r, int c, int count);
	void mark_up_left_diagonal(int r, int c, int count);
	void mark_down_right_diagonal(int r, int c, int count);
	void mark_down_left_diagonal(int r, int c, int count);
	void mark_up_vertical(int r, int c, int count);
	void mark_down_vertical(int r, int c, int count);
	void mark_left_horizontal(int r, int c, int count);
	void mark_right_horizontal(int r, int c, int count);

	bool mark_current(int _r, int _c);
};

char board::get_val(int r, int c) {
	if(r>7 || r<0)
		return -1;
	if(c>7 || c<0)
		return -1;

	return bp [(r*8) + c];
}

void board::set_val(int r, int c, char v) {
	if(r>7 || r<0)
		return;
	if(c>7 || c<0)
		return;

	bp [(r*8) + c] = v;
}

void board::print() {
	for(int i=0; i<8; i++) {
		for (int j=0; j<8; j++){
			cout << get_val(i,j);
		}
		cout << "\n";
	}
	cout << "\n\n";
}

board::board(string s): bp(0) {
	const char * cp = s.c_str();
	bp = new char[8*8];
	int bpi = 0;

	for(int i=0; i<s.length(); i++) {
		char c = cp[i];

		if(c == '/')
			continue;
		else if(c >= '0' && c <= '9') {
			int n = c - 48;
			while(n--) {
				bp[bpi++] =  'S';
			}
		}
		else {
			bp[bpi++] = c;
		}

	}
}

bool board::mark_current(int _r, int _c) {
	char c = get_val(_r, _c);
	if(c == -1) // reached bounds
		return false;
	else if(c == 'S' || c == '*'){
		set_val(_r, _c, '*');
		return true; // proceeding further is possible
	}
	else
		return false; // another valid piece block move not valid for knight
}

void board::mark_up_right_diagonal(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		r -= 1;
		c += 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_up_left_diagonal(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		r -= 1;
		c -= 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_down_right_diagonal(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		r += 1;
		c += 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_down_left_diagonal(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		r += 1;
		c -= 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_up_vertical(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		r -= 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_down_vertical(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		r += 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_left_horizontal(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		c -= 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_right_horizontal(int r, int c, int count) {
	for(int i=1; i<=count; i++) {
		c += 1;
		if(!mark_current(r, c))
			return;
	}
}

void board::mark_black_pawn_damage(int r, int c) {
	mark_down_left_diagonal(r,c,1);	mark_down_right_diagonal(r,c,1);
}

void board::mark_white_pawn_damage(int r, int c) {
	mark_up_right_diagonal(r,c,1);	mark_up_left_diagonal(r,c,1);
}

void board::mark_knight_damage(int r, int c){
	mark_current(r-1, c+2);	mark_current(r+1, c+2); // right
	mark_current(r-1, c-2); mark_current(r+1, c-2); // left
	mark_current(r-2, c+1); mark_current(r-2, c-1); // up
	mark_current(r+2, c+1); mark_current(r+2, c-1); // down
}

void board::mark_bishop_damage(int r, int c){
	mark_up_right_diagonal(r,c,8);	mark_up_left_diagonal(r,c,8); // up diagonals
	mark_down_left_diagonal(r,c,8);	mark_down_right_diagonal(r,c,8); // down diagonals
}

void board::mark_rook_damage(int r, int c){
	mark_up_vertical(r,c,8); mark_down_vertical(r,c,8); // up & down
	mark_left_horizontal(r,c,8); mark_right_horizontal(r,c,8); // right & left
}

void board::mark_queen_damage(int r, int c){
	mark_up_vertical(r,c,8);	mark_down_vertical(r,c,8); // vertical
	mark_left_horizontal(r,c,8); mark_right_horizontal(r,c,8); // horizontal
	mark_up_right_diagonal(r,c,8);	mark_up_left_diagonal(r,c,8); // up diagonals
	mark_down_left_diagonal(r,c,8);	mark_down_right_diagonal(r,c,8); //down diagonals
}

void board::mark_king_damage(int r, int c){
	mark_up_vertical(r,c,1); mark_down_vertical(r,c,1); // vertical
	mark_left_horizontal(r,c,1); mark_right_horizontal(r,c,1); // horizontal
	mark_up_right_diagonal(r,c,1); mark_up_left_diagonal(r,c,1); // up diagonals
	mark_down_left_diagonal(r,c,1);	mark_down_right_diagonal(r,c,1); //down diagonals
}

int solve(string s) {
	board b(s);
	//b.print();
	for(int i=0; i<8; i++) {
		for (int j=0; j<8; j++){
			switch(b.get_val(i,j)) { // PNBRQK
				case 'P':
				b.mark_white_pawn_damage(i,j);
				break;

				case 'p':
				b.mark_black_pawn_damage(i,j);
				//b.mark_pawn_damage(i,j);
				break;

				case 'N':
				case 'n':
				b.mark_knight_damage(i,j);
				break;

				case 'B':
				case 'b':
				b.mark_bishop_damage(i,j);
				break;

				case 'R':
				case 'r':
				b.mark_rook_damage(i,j);
				break;

				case 'Q':
				case 'q':
				b.mark_queen_damage(i,j);
				break;

				case 'K':
				case 'k':
				b.mark_king_damage(i,j);
				break;

			}
		}
	}

	int count = 0;
	for(int i=0; i<8; i++) {
		for (int j=0; j<8; j++){
			if(b.get_val(i,j) == 'S')
				count++;
		}
	}
	//b.print();
	return count;
}

int main() {
	string s;
	while(getline(cin, s)){
		int r = solve(s);
		cout << r << "\n";
	}
}
