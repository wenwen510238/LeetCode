class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = -1, fresh = 0;
        queue<pair<int, int>>q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1)    fresh++;
            }
        } 
        if(fresh == 0)  return 0;
        while(!q.empty()){
            int size = q.size(); 
            for(int i=0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();
                for(auto& dir: direction){
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        if(fresh != 0)  return -1;
        return minutes;
    }
};