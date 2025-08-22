class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int pos = n - 1;
        for(int i=0, j=n-1; i<=j;){
            if(abs(nums[i]) >= abs(nums[j])){
                res[pos] = nums[i] * nums[i];
                pos--;
                i++;
            }
            else{
                res[pos] = nums[j] * nums[j];
                pos--;
                j--;
            }
        }
        return res;
    }
};