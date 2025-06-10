class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for(int num: nums){
            if(!numSet.count(num-1)){
                int current = num + 1;
                int length = 1;
                while(numSet.count(current)){
                    length++;
                    current++;
                }
                longest = max(longest, length);
                if(longest > nums.size()/2) return longest;
            }
        }
        return longest;
    }
};