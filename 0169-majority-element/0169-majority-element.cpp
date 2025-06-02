class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, cnt = 0;
        for(int num:nums){
            if(cnt == 0)    candidate = num;
            if(num == candidate)    cnt++;
            else    cnt--;
        }
        return candidate;
    }
};