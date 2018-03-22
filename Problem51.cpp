//
// Created by czk on 18-3-22.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



class Solution{
public:
    vector<vector<string> > solveNQueens(int n){
        vector<vector<string> > solution;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(solution, board, n, 0);
        return solution;
    }
private:
    void solveNQueensHelper(vector<vector<string> >& solution, vector<string> board, int n, int row){
        if (row == n) {
            // In this case, the board is already filled with queens
            solution.push_back(board);
            return;
        } else {
            for(int i = 0;i < n;i++){
                if (check(i, row, board, n)) {
                    board[row][i] = 'Q';
                    solveNQueensHelper(solution, board, n, row + 1);
                    board[row][i] = '.';
                }
            }
        }

    }

    bool check(int x1, int y1, const vector<string>& board, int n){
        for(int i = 0;i < y1;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'Q'){
                    if (x1 == j){
                        return false;
                    }
                    else if (abs(x1 - j) == abs(y1 - i)) {
                        return false;
                    }
                    else{
                        continue;
                        }}
                }
            }
        return true;
    }


};


int main(void){[1] = {std::vector<std::__cxx11::basic_string, std::allocator>}
    vector<vector<string> > solution;
    Solution queen = Solution();
    solution = queen.solveNQueens(4);
    return 0;
}
