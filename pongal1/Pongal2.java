import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Pongal2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for (int t = 0; t < tc; ++t) {
			String a = br.readLine();
			String b = br.readLine();
			int n = a.length();
			int offset = n;
			int[] firstIndex = new int[2 * n + 1];
			for (int i = -n; i <= n; ++i) {
				firstIndex[i + offset] = -2;
			}
			firstIndex[0 + offset] = -1;
			int ans = 0;
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				sum += (a.charAt(i) - '0') - (b.charAt(i) - '0');
//				System.out.println("sum = " + sum);
				if (firstIndex[sum + offset] == -2) {
					firstIndex[sum + offset] = i;
				} else {
					ans = Math.max(ans, i - firstIndex[sum + offset]);
				}
			}
			System.out.println(ans);
		}
	}
}
