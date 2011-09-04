// Author: Swarnaprakash
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MagicSquare {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		if (testCases < 0 || testCases > 100) {
			throw new RuntimeException("Invalid Constraints");
		}
		for (int i = 0; i < testCases; ++i) {
			int n = Integer.parseInt(br.readLine());
			if (n < 1 || testCases > 100) {
				throw new RuntimeException("Invalid Constraints");
			}
			System.out.println(n * (n * n + 1) / 2);
		}
	}
}
