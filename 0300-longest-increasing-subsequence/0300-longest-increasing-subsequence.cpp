class Solution {
public:
    vector<int> res;
    int lengthOfLIS(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end())   res.push_back(nums[i]);
            else    *it = nums[i];
        }
        return res.size();
    }
};