import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class I {

	void run() throws IOException {
		Scanner scan = new Scanner(new File("regular.in"));
		FileWriter cout = new FileWriter(new File("regular.out"));
		int n = scan.nextInt();
		BigInteger[][][] dp = new BigInteger[66][66][66];
		for (int i = 0; i < 66; i++) {
			for (int j = 0; j < 66; j++) {
				for (int k = 0; k < 66; k++)
					dp[i][j][k] = BigInteger.ZERO;
			}
		}
		dp[0][0][0] = BigInteger.ONE;
		// System.out.println(dp[10][10][10]);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					if (i < j || j < k || i < k)
						continue;
					if (i + 1 >= j && j >= k)
						dp[i + 1][j][k] = dp[i + 1][j][k].add(dp[i][j][k]);
					if (i >= j + 1 && j + 1 >= k)
						dp[i][j + 1][k] = dp[i][j + 1][k].add(dp[i][j][k]);
					if (i >= j && j >= k + 1)
						dp[i][j][k + 1] = dp[i][j][k + 1].add(dp[i][j][k]);
					// System.out.println("FUCK");
				}
			}
		}
		cout.write(dp[n][n][n].toString());
		
		cout.close();
		scan.close();
	}

	public static void main(String[] args) throws IOException {
		new I().run();
	}
}
