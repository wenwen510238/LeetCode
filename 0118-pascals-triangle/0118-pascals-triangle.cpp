class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        numRows--;
        while(numRows--){
            vector<int> element;
            element.push_back(1);
            int row = res.size();
            for(int i=1; i<row; i++){
                element.push_back(res[row-1][i] + res[row-1][i-1]);
            }
            element.push_back(1);
            res.push_back(element);
        }
        return res;
    }
};