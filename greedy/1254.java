package ps;
import java.util.*;

class Main{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String s_expression = sc.nextLine();
		
		List<Integer> numbers = new ArrayList<>();
		
		String num_s = "";
		for(int i = 0; i < s_expression.length(); i++) {			
			if((s_expression.charAt(i) == '+' || s_expression.charAt(i) == '-') && num_s != "") {
				numbers.add(Integer.parseInt(num_s));
				num_s = "";
			}
			if(i == s_expression.length()-1) {
				num_s += s_expression.charAt(i);
				numbers.add(Integer.parseInt(num_s));
				break;
			}
			num_s += s_expression.charAt(i);
		}
		
		int ans = 0;
		boolean hasMinus = false;
		for(int num:numbers) {
			if(num < 0) hasMinus = true;
			if(num >0 && hasMinus) num *= -1;
			ans += num;
		}
		System.out.println(ans);
	}
}	