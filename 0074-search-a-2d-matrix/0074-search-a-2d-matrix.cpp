class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        // 幫每個位置編號 1~n*m-1
        int left = 0;
        int right = row * col -1;

        while(left <= right){
            int mid = (left + right) / 2;
            int r, c;
            if(mid == 0){
                r = 0;
                c = 0;
            }
            else{
                r = mid / col;
                c = mid % col;
            }
            if(matrix[r][c] == target)    return true;
            else if(matrix[r][c] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};