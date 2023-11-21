package abcabc;
import java.util.*;
import java.io.*;

class Main {
    static Scanner sc = new Scanner(System.in);
    static boolean checked[] = new boolean[9];
    static List<Integer> inputVal = new ArrayList<>();
    static int ans[] = new int[9];
    static int n;
    public static void main(String[] args) {
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
        	inputVal.add(i+1);
        }

        permutation(0);
    }

    public static void permutation(int depth) {
    	if(depth == inputVal.size()) {
    		printAll(ans);
    		return;
    	}
    	for(int i = 0; i < inputVal.size(); i++) {
    		if(!checked[i]) {
    			checked[i] = true;
    			ans[depth] = inputVal.get(i);
    			permutation(depth+1);
    			checked[i] = false;
    		}
    	}
    }
    
    public static void printAll(int[] inputVal) {
    	for(int i = 0; i < n; i++) {
            System.out.print(inputVal[i] + " ");

    	}
        System.out.println();
    }
}
