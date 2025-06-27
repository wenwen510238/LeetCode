class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int product = 1;
        for(int i=1; i<n; i++){
            res[i] = product * nums[i-1];
            product = res[i];
        }
        product = nums[n-1];
        for(int i=n-2; i>=0; i--){
            res[i] *= product;
            product *= nums[i];
        }
        return res;
    }
};