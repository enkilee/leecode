//你的音乐播放器里有 N 首不同的歌，在旅途中，你的旅伴想要听 L 首歌（不一定不同，即，允许歌曲重复）。请你为她按如下规则创建一个播放列表：

//每首歌至少播放一次。
//一首歌只有在其他 K 首歌播放完之后才能再次播放。
//返回可以满足要求的播放列表的数量。由于答案可能非常大，请返回它模 10^9 + 7 的结果。
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