import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> nums = new ArrayList<>();

        for(int i = 0; i < n; i++){
            nums.add(sc.nextInt());
        }

        long sum[] = new long[n];
        sum[0] = nums.get(0);

        //make sum arr

        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + nums.get(i);
        }

        for(int i = 0; i < m; i++){
            int s = sc.nextInt()-1;
            int e = sc.nextInt()-1;
            if(s >= 1){
                System.out.println(sum[e] - sum[s-1]);
            } else{
                System.out.println(sum[e]);
            }
        }
    }
}