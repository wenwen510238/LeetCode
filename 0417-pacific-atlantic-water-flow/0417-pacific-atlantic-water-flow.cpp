class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacVisit(n, vector<bool>(m, false));
        vector<vector<bool>> atlVisit(n, vector<bool>(m, false));

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
                if(pacVisit[i][j] && atlVisit[i][j])    res.push_back({i, j});
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visit){
        visit[r][c] = true;
        for(auto& dir: dirs){
            int newR = r + dir[0];
            int newC = c + dir[1];
            if(newR<0 || newR>=heights.size() || newC<0 || newC>=heights[0].size()) continue;
            if(visit[newR][newC])   continue;
            if(heights[newR][newC] < heights[r][c]) continue;

            dfs(heights, newR, newC, visit);
        }
    }
};