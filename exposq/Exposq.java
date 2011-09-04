import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Exposq {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		if (tc < 0 || tc > 200) {
			throw new Exception("Invalid constraints");
		}
		for (int t = 0; t < tc; ++t) {
			long n = Long.parseLong(br.readLine());
			if (n < 0 || n > 1000000000000000L) {
				throw new Exception("Invalid constraints");
			}

			int log_n = 0;
			while (n > 0) {
				++log_n;
				n /= 2;
			}
			long ans = 1;
			for (int i = 0; i < log_n + 1; ++i) {
				ans *= 2;
			}
			--ans;
			System.out.println(ans);
		}
	}

}
