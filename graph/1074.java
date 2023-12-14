package ps;
import java.util.*;
import java.math.*;

class Main{
	static int num = 0;
	static int r;
	static int c;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = (int)Math.pow(2, sc.nextInt());
		r = sc.nextInt();
		c = sc.nextInt();
		
		dfs(0, n-1, 0, n-1);

				
	}
	
	public static void dfs(int sX, int eX, int sY, int eY) {
		if(sX == c && sY == r) {
			System.out.println(num);
			return;
		}
		if(sX > c || eX < c || sY > r || eY < r) {
			num += (eX-sX+1) * (eX-sX+1);
			return;
		}

		int mX = (sX + eX)/2;
		int mY = (sY + eY)/2;

		if(sX >= eX || sY >= eY) {
			num++;
			return;
		}
		
		dfs(sX, mX, sY, mY);
		dfs(mX+1, eX, sY, mY);
		dfs(sX, mX, mY+1, eY);
		dfs(mX+1, eX, mY+1, eY);
	}
}