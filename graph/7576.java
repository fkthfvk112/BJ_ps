package ps;
import java.util.*;

class Main{
	static int tomatoMap[][];
	static boolean checked[][];
	static int n;
	static int m;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		
		tomatoMap = new int[n][m];
		checked = new boolean[n][m];
		
		Queue<Tomato> tomatos = new LinkedList<>();
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int toma = sc.nextInt();
				tomatoMap[i][j] = toma;
				if(toma == 1) {
					checked[i][j] = true;
					tomatos.add(new Tomato(i, j));
				}
			}
		}
		
		int days = getDays_bfs(tomatos);
		
		boolean canNotCon = false;
		for(int i = 0; i < n; i++) {
			if(canNotCon) break;
			for(int j = 0; j < m; j++) {
				if(tomatoMap[i][j] == 0) {
					canNotCon = true;
					break;
				}
			}
		}
		if(canNotCon) System.out.println(-1);
		else System.out.println(days-1);
	}
	
	public static int getDays_bfs(Queue<Tomato> tomatos) {
		int days = 0;
		Queue<Tomato> nextTomatos = new LinkedList<>();
		
		int dx[] = {1, 0, -1, 0};
		int dy[] = {0, 1, 0, -1};
		while(!tomatos.isEmpty()) {
			Tomato now = tomatos.poll();
			for(int i = 0; i < 4; i++) {
				int nextX = now.x + dx[i];
				int nextY = now.y + dy[i];
				
				boolean canGo = (
						nextX >= 0 && nextX < n &&
						nextY >= 0 && nextY < m &&
						checked[nextX][nextY] == false &&
						tomatoMap[nextX][nextY] == 0);
				if(canGo) {
					nextTomatos.add(new Tomato(nextX, nextY));
					tomatoMap[nextX][nextY] = 1;
					checked[nextX][nextY] = true;
				}
			}
			//임시 queue -> queue
			if(tomatos.isEmpty()) {
				while(!nextTomatos.isEmpty()) {
					tomatos.add(nextTomatos.poll());
				}
				days++;
			}
		}
		
		return days;
	}
}	

class Tomato{
	public int x;
	public int y;
	Tomato(int x, int y){
		this.x = x;
		this.y = y;
	}
}