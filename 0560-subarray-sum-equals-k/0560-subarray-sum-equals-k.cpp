class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int cnt = 0;
        int sum = 0;
        prefixSum[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(prefixSum.count(sum - k)) cnt += prefixSum[sum - k];
            prefixSum[sum]++;
        }
        return cnt;
    }
};