class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)    return 1;
        int curr = 2;
        for(int i=2; i<nums.size(); i++){
            if(nums[i] != nums[curr-2]){
                nums[curr] = nums[i];
                curr++;
            }
        }
        return curr;
    }
};