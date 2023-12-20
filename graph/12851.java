package ps;
import java.util.*;
import java.math.*;

class Main{
	public static int MAX = 100000;
	public static boolean checked[] = new boolean[MAX+1];
	public static int min = Integer.MAX_VALUE;
	public static int methodCnt = 0;
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		bfs(n, k);
		
		System.out.println(min);
		System.out.println(methodCnt);

	}
	
	public static void bfs(int n, int k) {
		Queue<Position> q = new LinkedList<>();
		q.add(new Position(n, 0));
		while(!q.isEmpty()) {
			Position now = q.poll();
			
			//System.out.println(now.x);
			if(now.x == k) {
				if(now.cnt < min) {
					methodCnt = 0;
					min = now.cnt;
				}
				if(now.cnt == min) {
					methodCnt++;
				}
				continue;
			}
			if(now.x != k) checked[now.x] = true;

			if(now.cnt + 1 <= min) {
				if(now.x-1 >= 0 && !checked[now.x-1]) {
					q.add(new Position(now.x-1, now.cnt+1));
				}
				if(now.x+1 <= MAX && !checked[now.x+1]) {
					q.add(new Position(now.x+1, now.cnt+1));
				}
				if(now.x*2 <= MAX && !checked[now.x*2]) {
					q.add(new Position(now.x*2, now.cnt+1));
				}
			}
		}
	}
}

class Position{
	int x;
	int cnt;
	Position(int x, int cnt){
		this.x = x;
		this.cnt = cnt;
	}
}