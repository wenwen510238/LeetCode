class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size(), Lmax=9;
        for(auto& w: wordDict){
            Lmax = max(Lmax, (int)w.size());
        }
        vector<bool> dp(n+1, 0);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            for(int j=max(0, i-Lmax); j<i; j++){
                if(dp[j] && dict.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};