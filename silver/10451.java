package abcabc;
import java.util.*;

public class Main{
	static int[] nodeList = new int[1001];
	static boolean[] checked = new boolean[1001]; 
	static Scanner sc = new Scanner(System.in);

	public static void main(String args[]) {
		int times = sc.nextInt();
		
		for(int time = 0; time < times; time ++) {
			int n = sc.nextInt();
			
			
			for(int i = 1; i <= n; i++) {
				int num = sc.nextInt();
				nodeList[i] = num;
			}
			

			int ans = 0;
			for(int i = 1; i <= n; i++) {
				if(!checked[i]) {
					circleGraph(i);
					ans++;
				}
			}
			
			System.out.println(ans);
			nodeList = new int[1001];
			checked = new boolean[1001];
		}
	}	
	
	public static void circleGraph(int src) {
		int nodeNum = src;
		while(true) {
			//System.out.println("now : " + nodeNum + " next : " + nodeList[src]);
			if(checked[nodeNum]) return;
			checked[nodeNum] = true;
			nodeNum = nodeList[nodeNum];
		}
	}
}