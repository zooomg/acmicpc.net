// 1793 타일링

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BigInteger[] DP = new BigInteger[256];
        DP[0] = new BigInteger("1");
        DP[1] = new BigInteger("1");
        DP[2] = new BigInteger("3");
        for (int i = 3; i <= 255; i++) {
            DP[i] = DP[i - 1].add(DP[i - 2].multiply(BigInteger.valueOf(2)));
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String line = br.readLine();
            if (line==null) break;
            int n = Integer.parseInt(line);
            System.out.println(DP[n]);
        }
    }
}

// 0 일때 아무것도 안하는 일이 경우의 수 1이되어 dp[0] = 1
// 망할

// 큰수 덧셈은 짜기 귀찮으니까 그냥 BingInteger 짱짱맨