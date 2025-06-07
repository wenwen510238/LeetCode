class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 0;
        else if(n == 2){
            if (nums[0] > nums[1])  return 0;
            else    return 1;
        }
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(mid >= 1 && mid <= n-2){
                if(nums[mid] >= nums[mid-1] && nums[mid] >= nums[mid+1]) return mid;
                else if(nums[mid] < nums[mid-1])    right = mid - 1;
                else left = mid + 1;
            } 
            else if(mid == 0){
                if(nums[mid] < nums[mid + 1])   return mid+1;
                return mid;
            } 
            else if(mid == n-1){
                if(nums[mid] < nums[mid - 1])   return mid-1;
                return mid;
            }    
        }
        return left;
    }
};