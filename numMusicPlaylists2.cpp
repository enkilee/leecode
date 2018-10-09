//������ֲ��������� N �ײ�ͬ�ĸ裬����;�У�����ð���Ҫ�� L �׸裨��һ����ͬ��������������ظ���������Ϊ�������¹��򴴽�һ�������б�

//ÿ�׸����ٲ���һ�Ρ�
//һ�׸�ֻ�������� K �׸貥����֮������ٴβ��š�
//���ؿ�������Ҫ��Ĳ����б�����������ڴ𰸿��ܷǳ����뷵����ģ 10^9 + 7 �Ľ����
class Solution {
    long long l = 1000000007;
public:
    long long numMusicPlaylists(int N, int L, int K) {
        long long head = 1;
        for (int i = N; i >= N-K+1; i--) 
            head = (head * i) % l;
        
        vector<vector<long long>> dp(L-K+1, vector<long long>(N-K+1));
        dp[0][0] = 1;
        for (int i = 1; i <= L-K; i++) {
            for (int j = 0; j <= N-K; j++) {
                if (j == 0)
                    dp[i][0] = (dp[i-1][0] * (N-K)) % l;
                else if (j < i)
                    dp[i][j] = (((j * dp[i-1][j-1]) % l + ((N-j-K) * dp[i-1][j]) % l) % l);
                else if (j == i)
                    dp[i][i] = dp[i-1][i-1] * i % l;
                else 
                    break;
            }
        }
        return (head * dp[L-K][N-K]) % l;
    }
};