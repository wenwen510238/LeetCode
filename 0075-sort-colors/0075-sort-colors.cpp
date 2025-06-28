class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, current = 0, p2 = nums.size()-1;
        while(current <= p2){
            if(nums[current] == 0){
                swap(nums[p0], nums[current]);
                p0++;
                current++;
            }
            else if(nums[current] == 1) current++;
            else{
                swap(nums[p2], nums[current]);
                p2--;
            }
        }
    }
};