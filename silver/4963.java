package abcabc;
import java.util.*;

public class Main{
	public static boolean checked[][] = new boolean [51][51];
	public static int map[][] = new int[51][51];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		

		Node node = null;
		while(true) {
			
			int w = sc.nextInt();
			int h = sc.nextInt();
			
			if(w == 0 && h == 0) break;
			
			//make map
			for(int i = 0; i < h; i++) {
				for(int j = 0; j < w; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			//count island
			int cnt = 0;
			for(int i = 0; i < h; i++) {
				for(int j = 0; j < w; j++) {
					if(map[i][j] == 1 && !checked[i][j]) {
						checkIsland(w, h, new Node(i, j));
						cnt ++;
					}
				}
			}
			System.out.println(cnt);
			checked = new boolean[51][51];
			map = new int[51][51];
		}
	}
	
	public static void checkIsland(int w, int h, Node startNode) {
		int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
		int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
		
		int islandCnt = 0;
		Queue<Node> q = new LinkedList<>();
		q.add(startNode);
		checked[startNode.x][startNode.y] = true;
		
		while(!q.isEmpty()) {
			Node now = q.poll();

			for(int i = 0; i < dx.length; i++) {
				boolean inSizeX = now.x + dx[i] >= 0 && now.x + dx[i] < h;
				boolean inSizeY = now.y + dy[i] >=0 && now.y + dy[i] < w;
				if(!inSizeX || !inSizeY) continue;
				boolean isLand = map[now.x+dx[i]][now.y+dy[i]] == 1;
				boolean notChecked = !checked[now.x + dx[i]][now.y + dy[i]];
				if(isLand && notChecked) {
					Node next = new Node(now.x + dx[i], now.y + dy[i]);
					q.add(next);
					checked[next.x][next.y] = true;
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