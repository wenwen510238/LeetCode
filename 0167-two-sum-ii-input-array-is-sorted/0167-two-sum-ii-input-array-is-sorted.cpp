class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<numbers.size(); i++){
            int remain = target - numbers[i];
            if(mp.find(remain) == mp.end()) mp[numbers[i]] = i+1;
            else    return {mp[remain], i+1};
        }
        return {};
    }
};