class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origin = image[sr][sc];
        if(origin != color) dfs(image, origin, sr, sc, color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int origin, int r, int c, int color){
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != origin)   return;
        image[r][c] = color;
        dfs(image, origin, r-1, c, color);
        dfs(image, origin, r+1, c, color);
        dfs(image, origin, r, c-1, color);
        dfs(image, origin, r, c+1, color);
        
    }
};