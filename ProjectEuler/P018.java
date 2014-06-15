// answer: 1074

import java.util.Scanner;

public class P018 {

	Scanner scan = new Scanner(System.in);

	public void run() {
		int n = scan.nextInt();
		int[][] a = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				a[i][j] = scan.nextInt();
			}
		}
		int[][] f = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			f[n][i] = a[n][i];
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				f[i][j] = Math.max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
			}
		}
		System.out.println(f[1][1]);
	}

	public static void main(String args[]) {
		new P018().run();
	}
}
