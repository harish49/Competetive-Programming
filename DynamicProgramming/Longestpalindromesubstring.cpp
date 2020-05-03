class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        string res = "";
        for(int gap = 0 ; gap < n ; gap++){
            for(int start = 0 ; (start+gap) < n ; start++ ){
                int end = start+gap;
                if(s[start]==s[end]){
                    dp[start][end] = ((start+1)>=(end-1))?1:dp[start+1][end-1];
                }
                if(dp[start][end] && (int(res.size())) < (gap+1)){
                    res = s.substr(start,gap+1);
                }
            }
        }
        return res;
    }
};
