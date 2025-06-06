class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getRC = [&](int num) -> pair<int, int>{
            int row = n - 1 - (num-1)/n;
            int col = (num - 1) % n;
            if((n-row) % 2 == 0)    col = n - 1 - col;
            return {row, col}; 
        };

        queue<pair<int, int>> q;
        vector<bool> visit(n*n+1, false);
        q.push({1, 0});
        visit[1] = true;
        while(!q.empty()){
            auto [curr, step] = q.front();
            q.pop();
            if(curr == n*n) return step;
            for(int i=1; i<=6 && curr+i<=n*n; i++){
                int next = curr + i;
                auto [r, c] = getRC(next);
                if(board[r][c] != -1)   next = board[r][c];
                if(!visit[next]){
                    visit[next] = true;
                    q.push({next, step+1});
                }    
            }
        }
        return -1;
    }
};