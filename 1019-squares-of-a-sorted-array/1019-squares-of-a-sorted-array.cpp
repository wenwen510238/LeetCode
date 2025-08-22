class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int &num: nums){
            num = num * num;
        }
        priority_queue<int> pq(nums.begin(), nums.end());

        for(int i=nums.size()-1; i>=0; i--){
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};