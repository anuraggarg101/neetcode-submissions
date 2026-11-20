class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.length();
        int b = text2.length();
        // vector<vector<int>> dp(a+1, vector<int>(b+1, 0));


        // for(int i=1;i<=a;i++) {
        //     for(int j=1;j<=b;j++) {
        //         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         if(text1[i-1] == text2[j-1]) {
        //             dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
        //         } 
        //     }
        // }
        // return dp[a][b];
        
        // vector<vector<int>> dp(2, vector<int>(b+1,0));

        // for(int i=1;i<=a;i++) {
        //     for(int j=1;j<=b;j++) {
        //         dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
        //         if(text1[i-1] == text2[j-1]) {
        //             dp[i%2][j] = max(dp[i%2][j], 1+dp[(i+1)%2][j-1]);
        //         }
        //     }
        // }
        // return dp[a%2][b];

        vector<int> dp(b + 1, 0);

        for (int i = 1; i <= a; i++) {

            int prevDiag = 0;

            for (int j = 1; j <= b; j++) {

                int temp = dp[j]; // save old dp[i-1][j]

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = 1 + prevDiag;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prevDiag = temp;
            }
        }

        return dp[b];
    }
};
