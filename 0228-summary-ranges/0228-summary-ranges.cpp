class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int n = nums.size();  
        vector<string> res;
        int start = nums[0];
        bool isContiguous = false;
        bool isLast = false;
        for(int i=0; i<n; i++){
            isContiguous = false;
            if(i == n-1) isLast = true;
            if(!isLast && nums[i]+1 == nums[i+1])  isContiguous = true;
            if(isLast || !isContiguous){
                if(start == nums[i]) res.push_back(to_string(start));
                else res.push_back(to_string(start) + "->" + to_string(nums[i]));
                if(!isLast){
                    start = nums[i+1];
                }
            }
        }
        return res;
    }
};