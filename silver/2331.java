package prac;
import java.util.*;
import java.io.*;
import java.lang.Math.*;

class Main{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		List<Integer> ansList = new ArrayList<>();
		
		int num = sc.nextInt();
		int p = sc.nextInt();
		int same = -1;
		
		ansList.add(num);
		while(true) {
			num = getNextNumber(num, p);
			//System.out.println(num);
			if(ansList.contains(num)) {
				same = num;
				break;
			}
			else {
				ansList.add(num);
			}
		}
		
		int ans = 0;
		for(int ele:ansList) {
			if(ele == same) break;
			ans++;
		}
		
		System.out.println(ans);
	}

	
	static int getNextNumber(int now, int p) {
		List<Integer> digits = new ArrayList<>();
		while(now != 0) {
			digits.add(now%10);
			now /= 10;
		}
		int nextNum = 0;
		for(int digit:digits) {
			nextNum += Math.pow(digit, p);
		}
		
		return nextNum;
	}
}

