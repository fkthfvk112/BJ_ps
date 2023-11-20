package abcabc;
import java.util.*;
import java.io.*;

public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		String inputString = sc.nextLine().toUpperCase();
		Map<Character, Integer> cMap = new HashMap<>();
		
		int ansCnt = 0;
		Character ans = null;
		boolean isDupli = false;
		for(int i = 0; i < inputString.length(); i++) {
			Character nowChar = inputString.charAt(i);
			cMap.putIfAbsent(nowChar, 0);
			cMap.put(nowChar, cMap.get(nowChar)+1);
			
			int nowCount = cMap.get(nowChar);
			if(nowCount >= ansCnt) {
				if(nowCount == ansCnt) {
					isDupli = true;
				}
				else {
					isDupli = false;

				}
				ansCnt = nowCount;
				ans = nowChar;
			}
		}
		
		if(isDupli) {
			System.out.println("?");
		}else {
			System.out.println(ans);
		}

	}

}
