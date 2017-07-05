// 12247 Jollo
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3399
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main { // UVA 12247 Jolla card game

	int findMin(int startVal, int p1[], int p2[]){
		HashMap<Integer, Boolean> h = new HashMap <Integer, Boolean>();
		h.put(p1[0], true); h.put(p1[1], true); h.put(p1[2], true);
		h.put(p2[0], true); h.put(p2[1], true);

		int i = startVal;
		for(; i<=53; i++) {
			if(h.containsKey(i))
				continue;
			break;
		}
		return i;
	}

	void printAns(int val) {
		if(val > 52) {
			System.out.println("-1");
		} else {
			System.out.println(val);
		}
	}

	void findValue(int p1[], int p2[]) {
		Arrays.sort(p1);
		Arrays.sort(p2);

		int ans = 100;

		if(p2[0] > p1[1]) {
			int start = 0;
			if(p2[0] > p1[2])
				start = 1;
			else
				start = p1[1] + 1;

			ans = findMin(start,p1, p2);
		}
		else if(p2[1] > p1[2]){
			ans = findMin(p1[2]+1,p1, p2);
		}
		else {
			ans = 100;
		}
		printAns(ans);
	}

	public static void main(String args[]) {
		Main M = new Main();
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextLine()) {
			String[] cards = sc.nextLine().split(" ");
			if(Integer.parseInt(cards[0]) == 0)
				break;

			int[] p1 = new int[3];
			p1[0] = Integer.parseInt(cards [0]);
			p1[1] = Integer.parseInt(cards [1]);
			p1[2] = Integer.parseInt(cards [2]);

			int[] p2 = new int[3];
			p2[0] = Integer.parseInt(cards [3]);
			p2[1] = Integer.parseInt(cards [4]);
			p2[2] = 100;
			M.findValue(p1, p2);
		}
	}
}
