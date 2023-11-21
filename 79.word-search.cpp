/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
        if (index == word.size()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
        
        char original = board[row][col];
        if (original != word[index]) return false;
        
        board[row][col] = 0;
        bool found = dfs(board, row - 1, col, word, index + 1) ||
                     dfs(board, row + 1, col, word, index + 1) ||
                     dfs(board, row, col - 1, word, index + 1) ||
                     dfs(board, row, col + 1, word, index + 1);
        
        board[row][col] = original;
        return found;
    }
};

// @lc code=end

