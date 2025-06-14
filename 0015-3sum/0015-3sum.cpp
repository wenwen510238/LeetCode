class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i] > 0) break;
            // if(nums[i] == nums[i+1])    continue;
            int target = 0 - nums[i];
            int l = i + 1, r = nums.size()-1;
            while(l < r){
                if(nums[l] + nums[r] == target){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l] == nums[l+1])    l++;
                    while(l<r && nums[r] == nums[r-1])    r--;
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] > target)    r--;
                else l++;
            }
            while(i<nums.size()-2 && nums[i] == nums[i+1])i++;
        }
        return res;

    }
};
// -4 -1 -1 0 1 2