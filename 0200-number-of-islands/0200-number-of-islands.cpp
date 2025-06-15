class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    int len = 0;
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] == '0')  return ;
        if(grid[row][col] == '1')   grid[row][col] = '0';

        dfs(grid, row+1, col);
        dfs(grid, row, col+1);
        dfs(grid, row-1, col);
        dfs(grid, row, col-1);
    }
};