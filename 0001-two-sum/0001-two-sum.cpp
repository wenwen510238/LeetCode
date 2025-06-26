class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> number;
        for(int i=0; i<nums.size(); i++){
            int remain = target - nums[i];
            if(number.find(remain) != number.end()) return {number[remain], i};
            number[nums[i]] = i;
        }
        return {};
    }
};