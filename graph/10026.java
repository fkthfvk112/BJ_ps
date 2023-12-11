package abcabc;
import java.util.*;

public class Main{
	static char paint[][] = new char[101][101];
	static boolean checked[][] = new boolean[101][101];
	static int n;

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			String line = sc.next();
			for(int j = 0; j < n; j++) {
				paint[i][j] = line.charAt(j);
			}
		}
		
		int ansNormal = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!checked[i][j]) {
					bfs(new Node(i, j), false);
					ansNormal++;
				}
			}
		}
		
		System.out.print(ansNormal + " ");
		
		checked = new boolean[101][101];
		
		int ansBlind = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!checked[i][j]) {
					bfs(new Node(i, j), true);
					ansBlind++;
				}
			}
		}
		System.out.println(ansBlind);
	}
	
	static void bfs(Node node, boolean isBlind) {
		Queue<Node> q = new LinkedList<>();
		q.add(node);
		
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		
		while(!q.isEmpty()) {
			Node now = q.poll();
			for(int i = 0; i < 4; i++) {
				int nextX = now.x + dx[i];
				int nextY = now.y + dy[i];
				if(nextX > n || nextX < 0) continue;
				if(nextY > n || nextY < 0) continue;
				
				boolean sameCon = paint[nextX][nextY] == paint[now.x][now.y];
				if(isBlind && paint[now.x][now.y] == 'R' && paint[nextX][nextY] == 'G') {
					sameCon = true;
				}
				else if(isBlind && paint[now.x][now.y] == 'G' && paint[nextX][nextY] == 'R') {
					sameCon = true;
				}
				
				if(!checked[nextX][nextY] && sameCon) {
					checked[nextX][nextY] = true;
					q.add(new Node(nextX, nextY));
				}
			}
		}
	}
}

class Node{
	int x;
	int y;
	Node(int x, int y){
		this.x = x;
		this.y = y;
	}
}
