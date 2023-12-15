package ps;
import java.util.*;

class Main{
	static int ansZero = 0;
	static int ansOne = 0;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int dp[] = new int[41];
		int zero[] = new int[41];
		int one[] = new int[41];
		
		for(int i = 0; i < t; i++) {
			int n = sc.nextInt();
			zero[0] = 1;
			one[1] = 1;
			for(int j = 2; j <= n; j++) {
				zero[j] = zero[j-2] + zero[j-1];
				one[j] = one[j-2] + one[j-1];
			}
			System.out.println(zero[n] + " " + one[n]);
		}		
		
	}
}	