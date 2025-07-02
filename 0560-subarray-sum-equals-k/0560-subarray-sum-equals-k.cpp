class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int cnt = 0, sum = 0;
        for(auto& num: nums){
            sum += num;
            if(prefixSum.count(sum-k))  cnt+=prefixSum[sum-k];
            prefixSum[sum] ++;
        }
        return cnt;
    }
};
// 1 1 1 1 -1 1 1
// 1 2 3 4  3 4 5

// 1 1 1
// 1 1