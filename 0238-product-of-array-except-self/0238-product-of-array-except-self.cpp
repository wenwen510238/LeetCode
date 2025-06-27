class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero = 0;
        for(auto& num: nums){
            if(num != 0)    product *= num;
            else zero++;
        }

        for(auto& num: nums){
            if(zero == 0)   num = product / num;
            else if(zero == 1 && num == 0)  num = product;
            else num = 0;
        }
        return nums;
    }
};