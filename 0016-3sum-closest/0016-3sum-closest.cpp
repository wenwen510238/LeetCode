class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int close = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n-2; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if(abs(sum - target) < abs(close - target)) close = sum;
                if(sum == target) return target;
                else if(sum < target) l++;
                else r--;
            }
        }
        return close;
    }
};
// -5 -5 -4 0 0 3 3 4 5 