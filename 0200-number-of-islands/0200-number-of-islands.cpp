class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int land = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    land++;
                    FindLand(grid, i, j);
                }
            }
        }
        return land;
    }
    void FindLand(vector<vector<char>>& grid, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] != '1')   return;
        grid[row][col] = '0';

        FindLand(grid, row+1, col);
        FindLand(grid, row, col+1);
        FindLand(grid, row-1, col);
        FindLand(grid, row, col-1);
    }
};