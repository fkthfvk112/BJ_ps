package ps;
import java.util.*;
import java.math.*;

class Main{
	static boolean checked[] = new boolean[100001];
	static long min = Integer.MAX_VALUE;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		dfs(n, k);
		
		System.out.println(min);
	}
	
	public static void dfs(int n, int k) {	
		Queue<Position> queue = new LinkedList<>();

		queue.add(new Position(n, 0));
		while(!queue.isEmpty()) {
			Position now = queue.poll();
			
			if(now.x == k && now.expense < min) {
				min = now.expense;
				return;
			}
			
			if(now.expense <= Math.abs(n-k)) {
				if(now.x+1 <= 100000 && now.expense+1 <= min && !checked[now.x+1]) {
					queue.add(new Position(now.x+1, now.expense+1));
					checked[now.x+1] = true;
				}
				if(now.x-1 >= 0 && now.expense+1 <= min&& !checked[now.x-1]) {
					queue.add(new Position(now.x-1, now.expense+1));
					checked[now.x-1] = true;
				}
				if(now.x*2 <= 100000 && now.expense+1 <= min && !checked[now.x*2]) {
					queue.add(new Position(now.x *2, now.expense+1));
					checked[now.x*2] = true;
				}
			}
		}
	}
}

class Position{
	int x;
	long expense;
	Position(int x, long expense){
		this.x = x;
		this.expense = expense;
	}
}