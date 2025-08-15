class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        int res = 1;
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};