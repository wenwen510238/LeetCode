class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n; i++){
            if(i >= 1 && nums[i] == nums[i-1]) continue;
            int l = i + 1;
            int r = n - 1;
            int t = target - nums[i];
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == t) return target;
                else{
                    if(abs(sum+nums[i]-target) < abs(res-target)) res = sum + nums[i];
                    if(sum < t) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};
// -5 -5 -4 0 0 3 3 4 5 