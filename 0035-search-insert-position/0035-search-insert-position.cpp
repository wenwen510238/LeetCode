class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int mid = len/ 2;
        while(mid >= 0 && mid < len){
            if(nums[mid] == target) return mid;
            else if(mid-1>=0 && nums[mid] > target && nums[mid-1] < target)  return mid;
            else if(mid+1<len && nums[mid] < target && nums[mid+1] > target)  return mid+1;
            else if(nums[mid] < target)  mid++;
            else    mid--;
        }
        if(target < nums[0])    return 0;
        else return len;
    }
};