package ps;
import java.util.*;
import java.math.*;

public class Main {
	static int INF = Integer.MAX_VALUE;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int metric[][] = new int[501][2];
		int n = sc.nextInt();
		
		int dp[][] = new int[501][501];
		
		for(int i = 0; i < n; i++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			metric[i][0] = r;
			metric[i][1] = c;
		}
		
		for(int gap = 1; gap < n; gap++) {
			for(int i = 0; i < n-gap; i++) {//metric number
				dp[i][i+gap] = INF;
				for(int pivot = i; pivot < i+gap; pivot++) {
					int val = dp[i][pivot] + dp[pivot+1][i+gap] + (metric[i][0] * metric[pivot][1] * metric[i+gap][1]);
					dp[i][i+gap] = Math.min(dp[i][i+gap], val);
					System.out.println("gap : " + gap);
					System.out.println("k : " + pivot);
					System.out.println("j : " + (i + gap));

					System.out.println("i : " + i);

					System.out.println("result" + dp[i][i+gap]);
					
				}
			}
		}
		System.out.println(dp[0][n-1]);
	}

}
