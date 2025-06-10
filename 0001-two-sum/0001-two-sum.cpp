class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0; i<nums.size(); i++){
            int remain = target - nums[i];
            if(remain == nums[i]){
                if(mp.find(remain) != mp.end() && mp[remain].size()>1)  return {mp[remain][1], i};
            } 
            else if(mp.find(remain) != mp.end()) return {mp[remain][0], i};
        }
        return {};
    }
};