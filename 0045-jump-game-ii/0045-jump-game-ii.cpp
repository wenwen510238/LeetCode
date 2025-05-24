class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;
        int farthest = 0; //目前這一層能到達的最遠地方
        int end = 0; //目前這一層能到達的右邊邊界

        if (n == 1) return 0;

        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == end){
                jump++;
                end = farthest;
                if(end >= n-1)  break;
            }
        }
        return jump;
    }
};

