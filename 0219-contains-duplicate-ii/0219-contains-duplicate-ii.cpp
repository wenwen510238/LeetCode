class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> exist;
        for(int i=0; i<nums.size(); i++){
            if(exist.find(nums[i]) == exist.end()) exist[nums[i]] = i;
            else if(i - exist[nums[i]] <= k)    return true;
            else    exist[nums[i]] = i;
        }
        return false;
    }
};