class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(finLeft(nums, target));
        res.push_back(finRight(nums, target));
        return res;
    }
    int finLeft(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                result = mid;
                r = mid - 1;
            }
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return result;
    }
    int finRight(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                result = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return result;
    }
};