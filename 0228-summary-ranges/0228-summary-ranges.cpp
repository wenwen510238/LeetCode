class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int n = nums.size();  
        vector<string> res;
        int start = nums[0];
        int end = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == end + 1){
                end = nums[i];
            }
            else{
                if(start == end) res.push_back(to_string(start));
                else res.push_back(to_string(start) + "->" + to_string(end));
                start = nums[i];
                end = nums[i];
            }
        }
        if(start == end) res.push_back(to_string(start));
        else res.push_back(to_string(start) + "->" + to_string(end));
        return res;
    }
};