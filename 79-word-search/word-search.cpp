class Solution {
public:
    bool solve(int row , int col, vector<vector<char>>& board, string &word, int idx){

        int m = board.size();
        int n = board[0].size();

        if(idx == word.size()) return true;

        if(row < 0 || col < 0 || row >= m || col >= n) return false;
        if(board[row][col] != word[idx]) return false;
        
        char prev = board[row][col];
        board[row][col] = '#';

        //word matches
        bool ans = false;

        ans = ans || solve(row+1,col,board,word,idx+1);
        ans = ans || solve(row-1,col,board,word,idx+1);
        ans = ans || solve(row,col+1,board,word,idx+1);
        ans = ans || solve(row,col-1,board,word,idx+1);

        board[row][col] = prev;

        return ans;

    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                    if(solve(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }

        return false;

    }
};