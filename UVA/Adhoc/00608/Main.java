// 608 - Counterfeit Dollar
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=549
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

	class CD { // Counterfeit Dollar
		Vector<String> vs;
		HashMap<Character, Character> sm; // set map
		HashMap<Character, Integer> uc; // usage count

		CD () {
			vs = new Vector<String>();
			sm = new HashMap<Character, Character>();
			uc = new HashMap<Character, Integer> ();
			for(char c = 'A'; c<='L'; c++) {
				sm.put(c, '-');
				uc.put(c, 0);
			}
		}

		void markSafeDollars(String s) {
			for(int i=0; i<s.length(); i++) {
				char c = s.charAt(i);
				sm.put(c, 'S');
			}
		}

		char getTypeID(boolean isLight) {
			if(isLight)
				return 'X';
			else
				return 'Z';
		}

		void bumpUpUsageCount(char c) {
			Integer x = uc.get(c);
			uc.put(c, (x+1));
		}

		void setType(char c, boolean isLight) {
			Character type = sm.get(c);
			char newType = getTypeID(isLight);

			if(type == '-'){
				sm.put(c, newType);
				bumpUpUsageCount(c);
				return;
			}
			else if(type == 'S') {
				return;
			}

			if(newType != type) {
				bumpUpUsageCount(c);
				sm.put(c, 'S');
				return;
			}

			if(newType == type) {
				bumpUpUsageCount(c);
			}
		}

		void markUnsafeDollars(String s, boolean isLight) {
			for(int i=0; i<s.length(); i++) {
				char c = s.charAt(i);
				setType(c, isLight);
			}
		}

		void markUnsafeDollars(String left, String right, String result) {
			if(result.equals("up")) {
				markUnsafeDollars(right, true);
				markUnsafeDollars(left, false);
			}
			else {
				markUnsafeDollars(right, false);
				markUnsafeDollars(left, true);
			}
		}

		void addIteration(String left, String right, String result) {
			if(result.equals("even"))
				markSafeDollars(left+right);
			else
				markUnsafeDollars(left, right, result);
		}

		void solve() {
			int max = 0;
			char ac = 'w';
			for(char c = 'A'; c<='L'; c++) {
				if(sm.get(c) == '-' || sm.get(c) == 'S') {
					continue;
				}
				int k = uc.get(c);
				if(k>max){
					max = uc.get(c);
					ac = c;
				}
			}
			String weight;
			String light = "light";
			String heavy = "heavy";

			if(sm.get(ac)=='Z')
				weight = heavy;
			else
				weight = light;

			System.out.println(ac+" is the counterfeit coin and it is "+weight+".");
		}
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i=0; i<T; i++) {
			CD cd = new Main(). new CD();
			for(int j=0; j<3; j++) {
				String s1 = sc.next();
				String s2 = sc.next();
				String r = sc.next();
				cd.addIteration(s1, s2, r);
			}
			cd.solve();
 		}
	}
}
