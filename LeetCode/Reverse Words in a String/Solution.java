import java.util.*;

public class Solution {
	
	public String reverseWords(String s) {
		String[] words = s.split(" ");
		StringBuilder answer = new StringBuilder();
		for (int i = words.length - 1; i >= 0; i--) {
			if (words[i].equals("") == false) {
				answer.append(words[i] + " ");
			}
		}
		int length = answer.length();
		if (answer.length() == 0) {
			return "";
		} else {
			return answer.toString().substring(0, length - 1);
		}
	}

	public static void main(String args[]) {
		String str = "the sky is blue";
		System.out.println(new Solution().reverseWords(str));
	}
}