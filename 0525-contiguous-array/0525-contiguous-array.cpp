class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int sum = 0, maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)    sum -= 1;
            else sum += 1;
            if(prefixSum.count(sum))    maxLen = max(maxLen, i - prefixSum[sum]);
            else prefixSum[sum] = i;
        }
        return maxLen;
    }
};