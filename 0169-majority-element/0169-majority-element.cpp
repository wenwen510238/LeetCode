class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int half = nums.size()/2;
        for(int i=0; i<nums.size(); i++){
            if(++m[nums[i]] > half) return nums[i];
        }
        return 0;
    }
};