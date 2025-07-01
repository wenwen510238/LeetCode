class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int cnt = 0, prev;
        for(int start=0; cnt<n; start++){
            int current = start;
            prev = nums[start];
            do{
                int idx = (current + k) % n;
                swap(nums[idx], prev);
                current = idx;
                cnt++;
            }while(current != start);
        }
    }
};