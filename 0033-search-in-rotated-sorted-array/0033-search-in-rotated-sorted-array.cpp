class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int peak;
        // find peak
        if(nums[left] < nums[right])    peak = right;
        else{
            while(right - left > 1){
                int mid = (left + right) / 2;
                if(nums[mid] < nums[right]) right = mid;
                else left = mid;
            }
            if(nums[left] > nums[right])    peak = left;
            else    peak = right;
        }
        
        cout<<peak;
        //divide two subset to find target
        if(nums[peak] < target) return -1;
        else if(target >= nums[0])   return find(target, 0, peak, nums);
        else return find(target, peak+1, nums.size()-1, nums);
    }
    int find(int target, int left, int right, vector<int>& nums){
        // if(left >= nums.size()) return -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

// 5 6 7 0 1 2 3
// 7 0 1 2 3 5 6 