package abcabc;
import java.math.*;
import java.util.*;

class Main{
	static int dp[] = new int[15000002];
	static int t[] = new int[15000002];
	static int p[] = new int[15000002];
	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		for(int i = 1; i <= n; i++) {
			t[i] = sc.nextInt();
			p[i] = sc.nextInt();
		}
		
		int max = 0;
		for(int i = 1; i <= n + 1; i++) {
			if(max < dp[i]) {
				max = dp[i];
			}
			int next = i + t[i];
			
			if(next <= n+1) {
				dp[next] = Math.max(dp[next], p[i] + max);
			}
		}
		
		System.out.println(max);
	}
}