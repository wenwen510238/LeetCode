class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto& num: nums){
            if(cnt.find(num) != cnt.end())  return true;
            cnt[num] = 1;
        }
        return false;
    }
};