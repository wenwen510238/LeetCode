class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int total = 1, zero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) total *= nums[i];
            else    zero++;
        }
        for(int i=0; i<nums.size(); i++){
            if(zero > 1 || (zero == 1 && nums[i] != 0))    res[i] = 0;
            else if(zero == 1 && nums[i] == 0)    res[i] = total;
            else    res[i] = total/nums[i];
        }
        return res;
    }
};