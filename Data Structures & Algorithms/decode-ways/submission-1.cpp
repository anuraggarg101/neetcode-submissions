class Solution {

public:
    int numDecodings(string s) {
        int n = s.length();
        int count = 0;
        if(s[0] == '0') return 0;

        vector<int> dp(n+1,1);
        for(int i=1; i<n; i++) {
            bool can_form_single_char = (s[i] != '0');
            if(can_form_single_char) {
                dp[i+1] = dp[i];
            } else {
                dp[i+1] = 0;
            }
            
            bool can_form_two_char = (s[i-1] == '1') or (s[i-1] == '2' and s[i] <= '6' and s[i] >= '0');
            if(can_form_two_char) {
                dp[i+1] += dp[i-1];
            }
        }
        return dp[n];

    }
};
