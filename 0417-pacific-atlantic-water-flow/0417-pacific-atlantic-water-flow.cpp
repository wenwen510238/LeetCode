class Solution {
public:
    vector<vector<int>> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacVisit(n, vector<bool>(m, false));
        vector<vector<bool>> atlVisit(n, vector<bool>(m, false));
        vector<vector<int>> res;

        for(int i=0; i<m; i++){
            dfs(heights, 0, i, pacVisit);
            dfs(heights, n-1, i, atlVisit);
        }
        for(int i=0; i<n; i++){
            dfs(heights, i, 0, pacVisit);
            dfs(heights, i, m-1, atlVisit);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlVisit[i][j] && pacVisit[i][j])    res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visit){
        if(r<0 || r>=heights.size() || c<0 || c>=heights[0].size()) return;

        visit[r][c] = true;

        for(auto& dir: direction){
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr<0 || nr>=heights.size() || nc<0 || nc>=heights[0].size() || heights[r][c] > heights[nr][nc] || visit[nr][nc] == true) continue;
            dfs(heights, nr, nc, visit);
        }
    }
};