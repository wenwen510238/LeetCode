class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O')  findO(board, i, 0);
            if(board[i][m-1] == 'O')  findO(board, i, m-1);
        }  
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O')  findO(board, 0, i);
            if(board[n-1][i] == 'O')  findO(board, n-1, i);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                else if(board[i][j] == '1')    board[i][j] = 'O';
            }
        }
    }
    void findO(vector<vector<char>>& board, int row, int col){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != 'O')  return;
        board[row][col] = '1';
        findO(board, row+1, col);
        findO(board, row, col+1);
        findO(board, row, col-1);
        findO(board, row-1, col);
    }
};