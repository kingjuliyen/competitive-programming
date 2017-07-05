// 00696 - max knights on chess board
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=637
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

	int row;
	int col;

	Main(int r, int c) {
		row = r;
		col = c;
	}

	void printAns(int ans) {
		// "4 knights may be placed on a 2 row 3 column board."
		System.out.println(ans+" knights may be placed on a "+
								row+" row "+col+" column board.");
	}

	void solve() {

		if(row == 1 || col == 1) {
			printAns(Math.max(row,col));
			return;
		}

		if(row == 2 || col == 2) {
			int d = Math.max(row,col);

			if(d <= 4) {
				printAns(4);
				return;
			}

			if(d%2!=0)
				printAns(d+1);
			else {
				int v = (row*col)/4;
				v = (v+1)/2;
				v = v * 4;
				printAns(v);
			}
			return;
		}
		int a = ((row * col) +1 ) / 2;
		printAns(a);
	}


	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNextInt()) {
			int M = sc.nextInt();
			int N = sc.nextInt();
			if(M==0 && N==0)
				break;

			Main m = new Main(M,N);
			m.solve();
		}
	}
}
