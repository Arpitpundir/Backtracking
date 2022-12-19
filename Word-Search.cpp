class Solution {
public:
    bool existRecursive(int row, int col, vector<vector<bool> > &vis, vector<vector<char> > board, string word, int wordInd){
        int n = board.size(), m = board[0].size();
        if(wordInd == word.size()) return true;
        if(row<0 || row >= n || col<0 || col>=m) return false;
        if(vis[row][col]) return false;
        if(board[row][col] ==  word[wordInd]){
            vis[row][col] = true;
            if(existRecursive(row-1, col, vis, board, word, wordInd+1) 
            || existRecursive(row, col-1, vis, board, word, wordInd+1) 
            || existRecursive(row, col+1, vis, board, word, wordInd+1) 
            || existRecursive(row+1, col, vis, board, word, wordInd+1)){
                return true;
            }
        }
        vis[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool> > vis;
        vis.resize(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(existRecursive(0,0,vis,board, word, 0)) return true;
            }
        }
        return false;
    }
};