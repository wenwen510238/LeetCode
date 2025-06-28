class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        for(auto& num: nums){
            if(num == 0) p0++;
            else if(num == 1) p1++;
        }
        for(int i=0; i<nums.size(); i++){
            if(i < p0)  nums[i] = 0;
            else if(i < p0+p1)  nums[i]= 1;
            else nums[i] = 2;
        }
    }
};