//������ֲ��������� N �ײ�ͬ�ĸ裬����;�У�����ð���Ҫ�� L �׸裨��һ����ͬ��������������ظ���������Ϊ�������¹��򴴽�һ�������б�

//ÿ�׸����ٲ���һ�Ρ�
//һ�׸�ֻ�������� K �׸貥����֮������ٴβ��š�
//���ؿ�������Ҫ��Ĳ����б�����������ڴ𰸿��ܷǳ����뷵����ģ 10^9 + 7 �Ľ����
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        //��̬�滮��� DP solution
        // F(1,1,1)=1
        // F(2,2,1)=2
        // F()
        // F(N,L,K) = F(N - 1, L - 1, K) * N + F(N, L - 1, K) * (N - K)
        long dp[N + 1][L + 1], mod = 1e9 + 7;
        for (int i = K + 1; i <= N; ++i)
            for (int j = i; j <= L; ++j)
                if ((i == j) || (i == K + 1))
                    dp[i][j] = factorial(i);
                else
                    dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K))  % mod;
        return (int) dp[N][L];
    }

    long factorial(int n) {
        return n ? factorial(n - 1) * n % (long)(1e9 + 7) : 1;
    }
};