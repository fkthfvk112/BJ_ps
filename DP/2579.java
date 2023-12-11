package abcabc;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[]) {
		int dp[][] = new int[302][2];
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> steps = new ArrayList<>();
		steps.add(0);
		for(int i = 1; i <= n; i++) {
			steps.add(sc.nextInt());
		}
		
		dp[0][0] = 0;
		dp[1][0] = steps.get(1);
		dp[1][1] = steps.get(1);
		if(n >= 2) {
			dp[2][0] = steps.get(2);//바로 직전을 밟지 않음
			dp[2][1] = steps.get(2) + steps.get(1);//바로 직전을 밟음
		}
		
		
		for(int i = 3; i <= n; i++) {
			//바로 직전을 밟지 않음
			dp[i][0] =  Math.max(dp[i-2][0], dp[i-2][1]) + steps.get(i);	
			//바로 직전을 밟음
			dp[i][1] = dp[i-1][0] + steps.get(i);
		}
		
		System.out.println(Math.max(dp[n][0], dp[n][1]));
		
		
	}
}