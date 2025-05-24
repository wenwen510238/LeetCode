class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int leftTop = 0, rightTop = 0;
        int total = 0;

        while(left < right){
            if(height[left] < height[right]){
                leftTop = max(leftTop, height[left]);
                total += leftTop - height[left];
                left++;
            }
            else{
                rightTop = max(rightTop, height[right]);
                total += rightTop - height[right];
                right--;
            }
        } 
        return total;
    }
};
