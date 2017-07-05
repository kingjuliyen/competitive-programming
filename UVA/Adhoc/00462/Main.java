// 462 - Bridge Hand Evaluator
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=403
// author: Senthil Kumar Thangavelu, email: kingjuliyen @ google's email.com

import java.util.*;

public class Main {

	static HashMap <String, Integer> hv;
	static int SPADES = 0, HEARTS = 0, DIAMOND = 0, CLUBS = 0;

	// Each ace counts 4 points. Each king counts 3 points.
	// Each queen counts 2 points. Each jack counts one point.
	static int rule1 () { // check ace
		int p = 0;

		if (hv.containsKey("AS"))
			p += 4;
		if (hv.containsKey("AH"))
			p += 4;
		if (hv.containsKey("AD"))
			p += 4;
		if (hv.containsKey("AC"))
			p += 4;

		if (hv.containsKey("KS"))
			p += 3;
		if (hv.containsKey("KH"))
			p += 3;
		if (hv.containsKey("KD"))
			p += 3;
		if (hv.containsKey("KC"))
			p += 3;

		if (hv.containsKey("QS"))
			p += 2;
		if (hv.containsKey("QH"))
			p += 2;
		if (hv.containsKey("QD"))
			p += 2;
		if (hv.containsKey("QC"))
			p += 2;

		if (hv.containsKey("JS"))
			p += 1;
		if (hv.containsKey("JH"))
			p += 1;
		if (hv.containsKey("JD"))
			p += 1;
		if (hv.containsKey("JC"))
			p += 1;

		return p;
	}

	// Subtract a point for any king of a suit
	// in which the hand holds no other cards.
	static int rule2 () { // check king
		int p = 0;
		if (hv.containsKey("KS") && SPADES == 1)
			p--;
		if (hv.containsKey("KH") && HEARTS == 1)
			p--;
		if (hv.containsKey("KD") && DIAMOND == 1)
			p--;
		if (hv.containsKey("KC") && CLUBS == 1)
			p--;
		return p;
	}

	// Subtract a point for any queen in a suit in which
	// the hand holds only zero or one other cards.
	static int rule3 () { // check queen
		int p = 0;
		if (hv.containsKey("QS") && SPADES <= 2)
			p--;
		if (hv.containsKey("QH") && HEARTS <= 2)
			p--;
		if (hv.containsKey("QD") && DIAMOND <= 2)
			p--;
		if (hv.containsKey("QC") && CLUBS <= 2)
			p--;
		return p;
	}

	// Subtract a point for any jack in a suit in which
	// the hand holds only zero, one, or two other cards
	static int rule4 () { // check jack
		int p = 0;
		if (hv.containsKey("JS") && SPADES <= 3)
			p--;
		if (hv.containsKey("JH") && HEARTS <= 3)
			p--;
		if (hv.containsKey("JD") && DIAMOND <= 3)
			p--;
		if (hv.containsKey("JC") && CLUBS <= 3)
			p--;
		return p;
	}

	// if n occurences found in a suit return n times incr value
	static int handle_suit_contains(int n, int incr) {
		int p = 0;

		if(SPADES == n)
			p += incr;
		if(HEARTS == n)
			p += incr;
		if(DIAMOND == n)
			p += incr;
		if(CLUBS == n)
			p += incr;

		return p;
	}

    //Add a point for each suit in which the hand contains exactly two cards
	static int rule5 () {
		return handle_suit_contains(2, 1);
	}

	// Add two points for each suit in which the hand contains exactly one card
	static int rule6 () {
		return handle_suit_contains(1, 2);
	}

	// Add two points for each suit in which the hand contains no cards
	static int rule7 () {
		return handle_suit_contains(0, 2);
	}

	static void bookKeep(String s) {
		hv.put(s, 1);
		switch(s.charAt(1)) {
			case 'S':
				SPADES++;
				break;
			case 'H':
				HEARTS++;
				break;
			case 'D':
				DIAMOND++;
				break;
			case 'C':
				CLUBS++;
				break;
		}
	}

	static int stopped[]; // SHDC

	static boolean isAllStopped() {
		 stopped = new int[4];
		 stopped[0] = 0; stopped[1] = 0; stopped[2] = 0; stopped[3] = 0;

		if (hv.containsKey("AS"))
			stopped[0] += 1;
		if (hv.containsKey("AH"))
			stopped[1] += 1;
		if (hv.containsKey("AD"))
			stopped[2] += 1;
		if (hv.containsKey("AC"))
			stopped[3] += 1;

		if (hv.containsKey("KS") && SPADES >=2)
			stopped[0] += 1;
		if (hv.containsKey("KH")  && HEARTS >=2)
			stopped[1] += 1;
		if (hv.containsKey("KD")  && DIAMOND >=2)
			stopped[2] += 1;
		if (hv.containsKey("KC")  && CLUBS >=2)
			stopped[3] += 1;

		if (hv.containsKey("QS") && SPADES >=3)
			stopped[0] += 1;
		if (hv.containsKey("QH")  && HEARTS >=3)
			stopped[1] += 1;
		if (hv.containsKey("QD")  && DIAMOND >=3)
			stopped[2] += 1;
		if (hv.containsKey("QC")  && CLUBS >=3)
			stopped[3] += 1;

		boolean b = false;
		if(stopped[0] >0 && stopped[1] >0  &&
		   stopped[2] >0  && stopped[3] >0 )
			b = true;

		// System.out.println(" stopped[0] "+stopped[0]+
		// 					" stopped[1] "+stopped[1]+
		// 					" stopped[2] "+stopped[2]+
		// 					" stopped[3] "+stopped[3]
		// 				);
		// System.out.println("b == "+b);
		return b;

	}

	static void checkRules() {
		int p = 0;
		p += rule1(); 	//	System.out.println("after rule1 points == "+p+"\n");
		p += rule2(); 	//	System.out.println("after rule2 points == "+p+"\n");
		p += rule3(); 	//	System.out.println("after rule3 points == "+p+"\n");
		p += rule4(); 	//	System.out.println("after rule4 points == "+p+"\n");

		if(p>=16 && isAllStopped()){
			System.out.println("BID NO-TRUMP");
		}
		else {
			p += rule5(); 	//	System.out.println("after rule5 points == "+p+"\n");
			p += rule6(); 	//	System.out.println("after rule6 points == "+p+"\n");
			p += rule7(); 	//	System.out.println("after rule7 points == "+p+"\n");

			if(p<14) {
				System.out.println("PASS");
			}
			else {
				int big[] = new int[4];
				big[0] = SPADES; big[1] = HEARTS; big[2] = DIAMOND; big[3] = CLUBS;
				Arrays.sort(big);
				if(big[3] == SPADES) {
					System.out.println("BID S");
				}
				else if (big[3] == HEARTS){
					System.out.println("BID H");
				}
				else if(big[3] == DIAMOND) {
					System.out.println("BID D");
				}
				else if(big[3] == CLUBS) {
					System.out.println("BID C");
				}
			}
		}
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		while(sc.hasNextLine())
		{
			String ss[] = sc.nextLine().split(" ");
			hv = new HashMap<String, Integer>();
			SPADES = 0; HEARTS = 0; DIAMOND = 0; CLUBS = 0;
			for(String s: ss) {
				bookKeep(s);
			}
			checkRules();
		}
	}
}
