//你的音乐播放器里有 N 首不同的歌，在旅途中，你的旅伴想要听 L 首歌（不一定不同，即，允许歌曲重复）。请你为她按如下规则创建一个播放列表：

//每首歌至少播放一次。
//一首歌只有在其他 K 首歌播放完之后才能再次播放。
//返回可以满足要求的播放列表的数量。由于答案可能非常大，请返回它模 10^9 + 7 的结果。
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        //动态规划解决 DP solution
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