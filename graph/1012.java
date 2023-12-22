import java.util.*;

public class Main {
    public static boolean visited[][];
    public static int map[][];
    public static int m;
    public static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();

        for(int tc = 0; tc < testCase; tc++){
            m = sc.nextInt();
            n = sc.nextInt();
            int k = sc.nextInt();

            visited = new boolean[51][51];
            map = new int[51][51];

            List<Point> chabbages = new ArrayList<>();

            for(int i = 0; i < k; i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                map[x][y] = 1;
                chabbages.add(new Point(x, y));
            }

            int ans = 0;
            for(Point chabbage:chabbages) {
                if(visited[chabbage.x][chabbage.y]) continue;
                dfs(chabbage);
                ans++;
            }
            System.out.println(ans);
        }
    }
    public static void dfs(Point chabbage){
        Stack<Point> chabbageStack = new Stack<>();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        chabbageStack.push(chabbage);
        while(!chabbageStack.isEmpty()){
            Point now = chabbageStack.pop();
            for(int i = 0; i < 4; i++){
                if(now.x + dx[i] < 0 || now.x + dx[i] > m) continue;
                if(now.y + dy[i] < 0 || now.y + dx[i] > n) continue;
                if(visited[now.x + dx[i]][now.y + dy[i]]) continue;
                if(map[now.x + dx[i]][now.y + dy[i]] != 1) continue;;
                visited[now.x + dx[i]][now.y + dy[i]] = true;
                chabbageStack.push(new Point(now.x + dx[i], now.y + dy[i]));
            }
        }
    }
}

class Point{
    int x;
    int y;
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}