class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(nums[i] > 0) break;
            int remain = 0 - nums[i];
            int l = i + 1, r = n - 1;
            while(l < r){
                if(nums[l] + nums[r] < remain)  l++;
                else if(nums[l] + nums[r] > remain)  r--;
                else if(nums[l] + nums[r] == remain){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && l<n-1 && nums[l] == nums[l+1]) l++;
                    while(l<r && r>0 && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
            while(i < n-2 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};
// -4 -1 -1 0 1 2