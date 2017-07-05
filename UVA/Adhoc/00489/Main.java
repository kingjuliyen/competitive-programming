// 489 - Hangman Judge
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=430
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

	String p;
	String g;
	int stroke;
	HashMap<Character, Integer> h;
	HashMap<Character, Integer> wgh; // wrong guess hashmap

	Main(String _p, String _g) {
		p = _p;
		g = _g;
		stroke = 0;
		h = new HashMap<Character, Integer> ();
		wgh = new HashMap<Character, Integer> ();
	}

	int getUnsolved() {
		int v = 0;
		for(Character c: h.keySet()){
			v+= h.get(c);
		}
		return v;
	}

	void populateHashMap() {
		for(int i=0; i<p.length(); i++){
			char c = p.charAt(i);
			Integer x = h.get(c);
			if(x == null){
				h.put(c, 1);
			}
			else {
				int v = x;
				v++;
				h.put(c, v);
			}
		}
	}

	void solve(int round) {
		populateHashMap();
		for(int i=0; i<g.length(); i++) {
			char c = g.charAt(i);
			Integer x = h.get(c);
			if(x == null) {
				Integer w = wgh.get(c);
				if(w == null){
					stroke++;
					wgh.put(c, 1);
				}
			}
			else {
				h.put(c, 0);
			}
			if(getUnsolved()== 0 || stroke >= 7)
				break;
		}

		System.out.println("Round "+round);
		if(getUnsolved()== 0){
			System.out.println("You win.");
			return;
		}
		else if(stroke>=7){
			System.out.println("You lose.");
			return;
		}
		else if(stroke < 7 && getUnsolved() >0 ){
			System.out.println("You chickened out.");
			return;
		}
	}

	public static void main(String s[]) {
		Scanner sc = new Scanner(System.in);

		while(true) {
			int R = Integer.parseInt(sc.nextLine());
			if(R == -1)
				break;

			String puzzle = sc.nextLine();
			String guessed = sc.nextLine();

			Main m = new Main(puzzle, guessed);
			m.solve(R);
		}
	}
}
