package ps;
import java.util.*;

class Main{
	static int MAX_VAL = 101;
	static int table[][] = new int[MAX_VAL][MAX_VAL];
	static long memo[][] = new long[MAX_VAL][MAX_VAL];
	static int n;
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				table[i][j] = sc.nextInt();;
			}
		}
		
		long ans = dfs(new Node(0, 0, table[0][0]));
		System.out.println(ans);
	}
	
	public static long dfs(Node node) {
		long ans = 0;
		//System.out.println("x: " + node.x + "  y: " + node.y);
		if(node.x == n-1 && node.y == n-1) {
			//System.out.println("ok");
			return 1;
		}
		if(node.dis == 0) {
			return 0;
		}
		if(node.x + node.dis <= n-1) {
			if(memo[node.x + node.dis][node.y] == 0) {//메모가 있으면 사용
				ans += dfs(node.hopRight(node.dis));
			} 
			else {
				ans += memo[node.x + node.dis][node.y];
			}
		}
		
		if(node.y + node.dis <= n-1) {
			if(memo[node.x][node.y + node.dis] == 0) {
				ans += dfs(node.hopBottom(node.dis));
			} 
			else {
				ans += memo[node.x][node.y + node.dis];
			}
		}
		memo[node.x][node.y] = ans;//현재 값 메모이제이션
		
		return ans;
	}
}

class Node{
	int x;
	int y;
	int dis;
	Node(int x, int y, int dis){
		this.x = x;
		this.y = y;
		this.dis = dis;
	}
	public Node hopRight(int num) {
		return new Node(this.x + num, this.y, Main.table[this.x + num][this.y]);
	}
	
	public Node hopBottom(int num) {
		return new Node(this.x, this.y + num, Main.table[this.x][this.y + num]);
	}
}